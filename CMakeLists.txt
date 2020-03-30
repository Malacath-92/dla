cmake_minimum_required(VERSION 3.9)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(dla INTERFACE)
target_include_directories(dla INTERFACE "include")

if(DLA_BUILD_TESTS)
	add_library(dla_warnings INTERFACE)
	if(MSVC)
		target_compile_options(dla_warnings INTERFACE /W4 /WX /permissive-)
	else()
		target_compile_options(dla_warnings INTERFACE -Wall -Wextra -pedantic -Werror)
	endif()

	add_library(dla_test INTERFACE)
	target_link_libraries(dla_test INTERFACE dla dla_warnings)

	SET(CONAN_EXTRA_OPTIONS NO_OUTPUT_DIRS)
	include(cmake/conan.cmake)
	run_conan()

	enable_testing()
	add_subdirectory(test)
endif()