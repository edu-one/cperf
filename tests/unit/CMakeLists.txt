# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

include(CMakePrintHelpers)

add_executable(cperf_test cperf_test.cpp)

find_package(GTest)
target_link_libraries(cperf_test 
        PRIVATE cperf
        gtest::gtest)

include(GoogleTest)
gtest_discover_tests(cperf_test)
