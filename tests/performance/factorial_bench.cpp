/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include <benchmark/benchmark.h>
#include <benchmark/export.h>
#include <cperf.h>

static void BM_Factorial(benchmark::State &state) {
    for (auto _ : state) {
        dv::cperf::factorial(state.range(0));
    }
}
BENCHMARK(BM_Factorial)->Range(0, 8);
