cmake_minimum_required (VERSION 3.1)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

string(COMPARE EQUAL "Clang" "${CMAKE_CXX_COMPILER_ID}" CLANG)
string(COMPARE EQUAL "GNU" "${CMAKE_CXX_COMPILER_ID}" GNU)

if(GNU)
  option(ENABLE_CODE_COVERAGE "Enable code coverage for gcc" FALSE)

  if(ENABLE_CODE_COVERAGE)
    link_libraries(gcov)
    add_compile_options(--coverage -g -O0 -fno-elide-constructors -fno-inline -fno-inline-small-functions -fno-default-inline)
  endif()
endif()

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