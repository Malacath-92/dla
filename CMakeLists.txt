cmake_minimum_required(VERSION 3.1)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

string(COMPARE EQUAL "Clang" "${CMAKE_CXX_COMPILER_ID}" CLANG)
string(COMPARE EQUAL "GNU" "${CMAKE_CXX_COMPILER_ID}" GNU)

if(MSVC)
  add_compile_options(/W4 /WX /permissive-)
  add_compile_options("$<$<CONFIG:RELEASE>:/O2>")
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
  add_compile_options("$<$<CONFIG:RELEASE>:-O3>")
endif()

include_directories("include")

# Load Conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.14/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE "conanfile.txt" CMAKE_TARGETS BUILD missing)
conan_basic_setup(NO_OUTPUT_DIRS)

enable_testing()
function(dlaAddTest NAME)
  add_executable(${NAME} ${NAME}.cpp)
	add_test(${NAME} ${NAME})
endfunction()

add_subdirectory(test)