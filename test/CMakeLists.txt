add_executable(vm_tests
        core/test_chunk.cpp
)

target_include_directories(vm_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(vm_tests PRIVATE core GTest::gtest_main)

add_test(NAME test_chunk COMMAND vm_tests)