# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

include(CMakePrintHelpers)

add_executable(cperf_bench cperf_test.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(cperf_bench 
        PRIVATE cperf
        PRIVATE benchmark::benchmark_main)

#include(GoogleTest)
#gtest_discover_tests(cperf_bench)
