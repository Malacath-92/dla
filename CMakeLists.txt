cmake_minimum_required (VERSION 3.1)
project(dla LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

string(COMPARE EQUAL "Clang" "${CMAKE_CXX_COMPILER_ID}" CLANG)
string(COMPARE EQUAL "GNU" "${CMAKE_CXX_COMPILER_ID}" GNU)

if(GNU)
  option(ENABLE_CODE_COVERAGE "Enable code coverage for gcc" FALSE)

  if(ENABLE_CODE_COVERAGE)
    # Gather files to cover
    file(GLOB_RECURSE COVERALLS_FILES "${CMAKE_SOURCE_DIR}/*.h" "${CMAKE_SOURCE_DIR}/*.inl")

    # Download Coveralls setup script
    if(NOT EXISTS "${CMAKE_BINARY_DIR}/Coveralls.cmake")
      message(STATUS "Downloading Coveralls.cmake from https://github.com/JoakimSoderberg/coveralls-cmake")
      file(DOWNLOAD "https://raw.githubusercontent.com/JoakimSoderberg/coveralls-cmake/master/cmake/Coveralls.cmake" "${CMAKE_BINARY_DIR}/Coveralls.cmake")
      file(DOWNLOAD "https://raw.githubusercontent.com/JoakimSoderberg/coveralls-cmake/master/cmake/CoverallsClear.cmake" "${CMAKE_BINARY_DIR}/CoverallsClear.cmake")
      file(DOWNLOAD "https://raw.githubusercontent.com/JoakimSoderberg/coveralls-cmake/master/cmake/CoverallsGenerateGcov.cmake" "${CMAKE_BINARY_DIR}/CoverallsGenerateGcov.cmake")
    endif()

    # Setup and enable Coveralls
    include(${CMAKE_BINARY_DIR}/Coveralls.cmake)
    coveralls_turn_on_coverage()
    coveralls_setup("${COVERALLS_FILES}" ON ${CMAKE_BINARY_DIR})
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