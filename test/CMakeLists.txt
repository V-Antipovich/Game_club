cmake_minimum_required(VERSION 3.27)

add_executable(
        timestamp_test timestamp_test.cpp
)

target_link_libraries(
        timestamp_test
        gtest_main
        gtest
        source_lib
)

add_test(
        NAME timestamp_test
        COMMAND timestamp_test
)

add_executable(
        input_test input_test.cpp
)

target_link_libraries(
        input_test
        gtest_main
        gtest
        source_lib
)

add_test(
        NAME input_test
        COMMAND input_test
)

add_executable(
        parser_test parser_test.cpp
)

target_link_libraries(
        parser_test
        gtest_main
        gtest
        source_lib
)

add_test(
        NAME parser_test
        COMMAND parser_test
)
