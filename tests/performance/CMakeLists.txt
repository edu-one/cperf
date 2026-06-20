# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

include(CMakePrintHelpers)

add_executable(cperf_bench factorial_bench.cpp count_if_bench.cpp)

find_package(benchmark REQUIRED)
target_link_libraries(cperf_bench
        PRIVATE cperf
        PRIVATE benchmark::benchmark_main)

add_test(NAME cperf_bench COMMAND cperf_bench)
