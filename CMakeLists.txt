cmake_minimum_required(VERSION 3.9)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

string(COMPARE EQUAL "Clang" "${CMAKE_CXX_COMPILER_ID}" CLANG)

add_library(dla INTERFACE)
target_include_directories(dla INTERFACE "include")

option(DLA_BUILD_TESTS "Build test suite for dla" OFF)

if(CLANG AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL "9.0.0")
	option(DLA_GENERATE_TIMINGS "Build test suite for dla" OFF)
endif()

if(DLA_BUILD_TESTS)
	message(STATUS "Building dla test suite")

	add_library(dla_warnings INTERFACE)
	if(MSVC)
		target_compile_options(dla_warnings INTERFACE /W4 /WX /permissive-)
	else()
		target_compile_options(dla_warnings INTERFACE -Wall -Wextra -pedantic -Werror)
	endif()

	add_library(dla_test INTERFACE)
	target_link_libraries(dla_test INTERFACE dla dla_warnings)
	if(DLA_GENERATE_TIMINGS)
		target_compile_options(dla_test INTERFACE -ftime-trace)
	endif()

	get_property(IS_MULTI_GENERATOR GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
	if(NOT IS_MULTI_GENERATOR)
		# The default option is only useful to write package functions for binary libraries
		# Unsetting the default here does not make any difference for multi-generators, yet causes CI to fail
		SET(CONAN_EXTRA_OPTIONS NO_OUTPUT_DIRS)
	endif()
	
	include(cmake/conan.cmake)
	run_conan()

	enable_testing()
	add_subdirectory(test)
endif()

if(DLA_GENERATE_TIMINGS)

	add_library(dla_timing_base INTERFACE)
	target_link_libraries(dla_timing_base INTERFACE dla dla_warnings)
	target_compile_options(dla_timing_base INTERFACE -ftime-trace)

	function(dlaAddHeaderTiming PATH)
		message(STATUS "\tAdding header timing " ${PATH})
		
		get_filename_component(NAME ${PATH} NAME_WE)
		set(GENERATED_SOURCE "${CMAKE_BINARY_DIR}/${NAME}.cpp")
		file(WRITE ${GENERATED_SOURCE}
			"\
#include <${PATH}>
int main() {}")

		set(TIMING_TARGET ${NAME}_timing)
		add_executable(${TIMING_TARGET} ${GENERATED_SOURCE})
		target_link_libraries(${TIMING_TARGET} PRIVATE dla dla_timing_base)
		set_target_properties(${TIMING_TARGET} PROPERTIES
							  FOLDER dla_timing)
	endfunction()

	message(STATUS "Generating dla timing data")
	message(STATUS "Discovering all headers...")
	file(GLOB_RECURSE files RELATIVE ${CMAKE_SOURCE_DIR}"/include" "include/*.h")
	foreach(file ${files})
		dlaAddHeaderTiming(${file})
	endforeach()
endif()
