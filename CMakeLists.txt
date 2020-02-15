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

include_directories("include/dla")

# Load Conan
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.13/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_check(REQUIRED)
conan_cmake_run(CONANFILE "conanfile.txt" CMAKE_TARGETS BUILD missing)

if (MSVC)
  conan_basic_setup()
else()
  conan_basic_setup(NO_OUTPUT_DIRS)
endif()

enable_testing()
function(dlaAddTest NAME)
  message(STATUS "\tAdding test " ${NAME})

  add_executable(${NAME} ${NAME}.cpp)
  add_test(${NAME} ${NAME})
  set_target_properties(${NAME} PROPERTIES
                        FOLDER dla_tests)
  
  set(CONSTEXPR_NAME ${NAME}_constexpr)
  add_executable(${NAME}_constexpr ${NAME}.cpp)
  target_compile_definitions(${NAME}_constexpr PRIVATE DLA_TEST_CONSTEXPR)
	add_test(${NAME}_constexpr ${NAME}_constexpr)
  set_target_properties(${NAME}_constexpr PROPERTIES
                        FOLDER dla_tests)
endfunction()

add_subdirectory(test)