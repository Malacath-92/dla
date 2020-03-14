cmake_minimum_required(VERSION 3.9)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

string(COMPARE EQUAL "Clang" "${CMAKE_CXX_COMPILER_ID}" CLANG)
string(COMPARE EQUAL "GNU" "${CMAKE_CXX_COMPILER_ID}" GNU)

add_library(dla_warnings INTERFACE)
if(MSVC)
	target_compile_options(dla_warnings INTERFACE /W4 /WX /permissive-)
else()
	target_compile_options(dla_warnings INTERFACE -Wall -Wextra -pedantic -Werror)
endif()

include_directories("include/dla")

if(NOT MSVC)
  SET(CONAN_EXTRA_OPTIONS NO_OUTPUT_DIRS)
endif()

include(cmake/conan.cmake)
run_conan()

enable_testing()
add_subdirectory(test)