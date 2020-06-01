import os
import argparse
import json
import re
from pathlib import Path

parser = argparse.ArgumentParser(description='Collect all metrics data produced by clang -ftime-trace.')
parser.add_argument('-b', '--build_directory', help="The directory in which targets were compiled", required=True)
parser.add_argument('-t', '--target', help="Expected target, can be passed multiple times. Targets not passed will be ignored. Passed targets that are not found are considered a failed build.", action="append")
parser.add_argument('-v', '--verbose', help="Print verbose information", action="store_true")
parser.add_argument('-p', '--pretty', help="Output collected data into a pretty json file (using indentation and new-lines)", action="store_true")
args = parser.parse_args()

def is_expected_target(target_name):
    return not args.target or target_name in args.target

def get_missing_targets(found_targets):
    return [] if not args.target else [target for target in args.target if target not in found_targets]

def verbose_print(msg):
    if args.verbose:
        print(msg)

def verbose_print_ignore_once(ignored):
    if ignored not in verbose_print_ignore_once.ignored:
        verbose_print_ignore_once.ignored.append(ignored)
        verbose_print('\t\tIgnoring unkown "{}"'.format(ignored))
verbose_print_ignore_once.ignored = []

def is_dla_file(header):
    return '/dla/' in Path(header).as_posix()

def is_dla_symbol(symbol):
    return 'dla::' in symbol

def remove_prefix(string, prefix):
    return string[len(prefix):] if string.startswith(prefix) else string

def remove_suffix(string, suffix):
    return string[:-len(suffix)] if string.endswith(suffix) else string

collected_data = dict()
found_targets = []

target_name_regex = re.compile(r'([\w\-. ]+)\.dir')

verbose_print('Discovering all metrics data in "{}"...'.format(args.build_directory))
json_file_paths = Path(args.build_directory).glob('**/*.json')
for json_file_path in json_file_paths:
    with open(json_file_path, 'r') as json_file:
        file_content = json.load(json_file)
        if 'traceEvents' in file_content:
            target_name_candidates = target_name_regex.findall(json_file_path.as_posix())
            if not target_name_candidates:
                verbose_print('\tCould not determine name for target found in {}'.format(json_file_path))
                continue
            target_name = target_name_candidates[-1]
            if not is_expected_target(target_name):
                verbose_print('\tIgnoring target "{}"...'.format(target_name))
                continue

            verbose_print('\tCollecting metrics data for target "{}"...'.format(target_name))

            metrics_data = {
                'Build': 'Success',
                'Type': None,
                'Total': 0,
                'Frontend': 0,
                'Backend': 0,
                'Source': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                },
                'ParseClass': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                },
                'ParseTemplate': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                },
                'InstantiateClass': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                },
                'InstantiateFunction': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                },
                'CodeGen Function': {
                    'Total': 0,
                    'dla': [],
                    'stl': []
                }
            }

            for data_point in file_content['traceEvents']:
                data_point_name = data_point['name']
                if data_point_name in [ 'ExecuteCompiler', 'Total ExecuteCompiler' ]:
                    metrics_data['Total'] = data_point['dur']
                elif data_point_name in [ 'Total Frontend', 'Total Backend' ]:
                    data_point_name = data_point_name[len('Total '):]
                    metrics_data[data_point_name] = data_point['dur']
                elif data_point_name.startswith('Total'):
                    data_point_name = remove_prefix(data_point_name, 'Total ')
                    if data_point_name not in metrics_data:
                        verbose_print_ignore_once(data_point_name)
                        continue
                    metrics_data[data_point_name]['Total'] = data_point['dur']
                elif data_point_name not in metrics_data:
                    verbose_print_ignore_once(data_point_name)
                    pass
                elif data_point_name == 'Source':
                    source_name = data_point['args']['detail']
                    source_origin = 'dla' if is_dla_file(source_name) else 'stl'
                    metrics_data[data_point_name][source_origin].append({
                        'File': Path(source_name).name,
                        'Time': data_point['dur']
                    })
                elif data_point_name in [ 'ParseClass', 'ParseFunction', 'ParseTemplate',
                                          'InstantiateClass', 'InstantiateFunction',
                                          'CodeGen Function' ]:
                    symbol_name = data_point['args']['detail']
                    if not symbol_name.startswith(('_', 'std::_')):
                        symbol_origin = 'dla' if is_dla_file(symbol_name) else 'stl'
                        metrics_data[data_point_name][symbol_origin].append({
                            'Symbol': symbol_name,
                            'Time': data_point['dur']
                        })

            metrics_data['Original'] = file_content['traceEvents']

            if '/test/' in json_file_path.as_posix():
                verbose_print('\t\tTarget is a unit test suite.')
                metrics_data['Type'] = 'Test'
            else:
                verbose_print('\t\tTarget is a pure header metrics test.')
                metrics_data['Type'] = 'Header'

            if target_name in found_targets:
                print('ERROR: Target "{}" exists more than once.'.format(target_name))
                exit(1)

            collected_data[target_name] = metrics_data
            found_targets.append(target_name)

missing_targets = get_missing_targets(found_targets)
for missing_target in missing_targets:
    verbose_print('Could not find target "{}", considering this a failed build.'.format(missing_target))
    collected_data[missing_target] = {
        'Build': 'Failure'
    }

json_output = json.dumps(collected_data, indent=4 if args.pretty else None) 
  
with open(Path(args.build_directory) / Path("metrics.json"), "w") as output_file: 
    output_file.write(json_output) 