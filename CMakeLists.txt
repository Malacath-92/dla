cmake_minimum_required (VERSION 3.1)
project(dla LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
  add_compile_options(/W4 /WX /permissive-)
  add_compile_options("$<$<CONFIG:RELEASE>:/O3>")
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
  add_compile_options("$<$<CONFIG:RELEASE>:-O2>")
endif()

include_directories("include")

function(dlaAddTest NAME)
	add_executable(${NAME} ${NAME}.cpp)
	add_test(${NAME} ${NAME})
endfunction()

add_subdirectory(test)