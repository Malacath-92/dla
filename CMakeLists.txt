cmake_minimum_required (VERSION 3.1)
project (dla)

enable_testing()

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
  add_compile_options(/W4 /WX /permissive-)
else()
  add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

include_directories("include")

function(dlaAddTest NAME)
	add_executable(${NAME} ${NAME}.cpp)
	add_test(${NAME} ${NAME})
endfunction()

add_subdirectory(test)