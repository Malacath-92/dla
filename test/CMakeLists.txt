add_library(catch_main STATIC main.cpp)
target_link_libraries(catch_main PUBLIC CONAN_PKG::catch2)
set_target_properties(catch_main PROPERTIES
					  FOLDER dla_tests)

function(dlaAddTest NAME)
	message(STATUS "\tAdding test " ${NAME})

	set(TEST_NAME ${NAME})
	
	add_executable(${TEST_NAME} ${NAME}.cpp)
	target_link_libraries(${TEST_NAME} PRIVATE catch_main dla_test)
	add_test(${TEST_NAME} ${TEST_NAME})
	set_target_properties(${TEST_NAME} PROPERTIES
						  FOLDER dla_tests)

	set(CONSTEXPR_NAME ${NAME}_constexpr)
	add_executable(${CONSTEXPR_NAME} ${NAME}.cpp)
	target_link_libraries(${CONSTEXPR_NAME} PRIVATE catch_main dla_test)
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
