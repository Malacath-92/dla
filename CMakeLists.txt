cmake_minimum_required (VERSION 3.1)
project (dla)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE dla_test_HEADERS "test/*.h" "include/*.h" "include/*.inl")
file(GLOB_RECURSE dla_test_SOURCES "test/*.cpp")

add_executable(dla_test ${dla_test_SOURCES} ${dla_test_HEADERS})

if(MSVC)
  target_compile_options(dla_test PRIVATE /W4 /WX /permissive-)
else()
  target_compile_options(dla_test PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

include_directories("include")