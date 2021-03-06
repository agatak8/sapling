enable_testing()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)

foreach(testSrc ${TEST_SRCS})
        get_filename_component(testName ${testSrc} NAME_WE)

        add_executable(${testName} ${testSrc})

        target_compile_definitions(${testName} PRIVATE EXAMPLES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/examples/" SAPLING_PATH="${CMAKE_CURRENT_SOURCE_DIR}/Sapling")
        target_link_libraries(${testName} ${Boost_LIBRARIES} AST Parser Token Scanner)

        set_target_properties(${testName} PROPERTIES 
            RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/tests/bin)

        add_test(NAME ${testName} 
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/bin
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/bin/${testName} )
endforeach(testSrc)