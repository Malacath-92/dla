add_library(catch_main STATIC main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)

function(dlaAddTest NAME)
  message(STATUS "\tAdding test " ${NAME})

  add_executable(${NAME} ${NAME}.cpp)
  target_link_libraries(${NAME} PRIVATE catch_main)
  add_test(${NAME} ${NAME})
  set_target_properties(${NAME} PROPERTIES
                        FOLDER dla_tests)
  
  set(CONSTEXPR_NAME ${NAME}_constexpr)
  add_executable(${CONSTEXPR_NAME} ${NAME}.cpp)
  target_link_libraries(${CONSTEXPR_NAME} PRIVATE catch_main)
  target_compile_definitions(${CONSTEXPR_NAME} PRIVATE DLA_TEST_CONSTEXPR)
	add_test(${CONSTEXPR_NAME} ${CONSTEXPR_NAME})
  set_target_properties(${CONSTEXPR_NAME} PROPERTIES
                        FOLDER dla_tests)
endfunction()

message(STATUS "Discovering all tests...")
file(GLOB files "*.cpp")
foreach(file ${files})
  get_filename_component(filename ${file} NAME_WE)
  if (NOT ${filename} STREQUAL "main")
    dlaAddTest(${filename})
  endif()
endforeach()
