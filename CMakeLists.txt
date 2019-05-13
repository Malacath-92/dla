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

enable_testing()
function(dlaAddTest NAME)
  add_executable(${NAME} ${NAME}.cpp)
	add_test(${NAME} ${NAME})
endfunction()

add_subdirectory(test)