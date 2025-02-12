/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include <benchmark/benchmark.h>
#include <cperf.h>
#include <random>
#include <memory>


namespace {
    using Vector2DPtr = std::unique_ptr<dv::cperf::Vector2D>;

    Vector2DPtr generate_random_data(size_t rows, size_t cols) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(-1000, 1000);

        auto result = std::make_unique<dv::cperf::Vector2D>(rows);
        for (auto& row : *result) {
            row.resize(cols);
            for (auto& val : row) {
                val = dis(gen);
            }
        }
        return result;
    }

    void BM_CountIf(benchmark::State& state, size_t rows, size_t cols, 
                    std::function<size_t(const dv::cperf::Vector2D&, dv::cperf::Pred)> count_fn) {
        auto data = generate_random_data(rows, cols);
        auto pred = [](int x) { return x > 0; };

        for (auto _ : state) {
            benchmark::DoNotOptimize(count_fn(*data, pred));
        }
        state.SetComplexityN(rows * cols);
    }

    #define BENCHMARK_COUNTERS(rows, cols) \
        BENCHMARK_CAPTURE(BM_CountIf, \
            "count_if_range_" #rows "x" #cols, rows, cols, dv::cperf::count_if_range); \
        BENCHMARK_CAPTURE(BM_CountIf, \
            "count_if_row_major_" #rows "x" #cols, rows, cols, dv::cperf::count_if_row_major); \
        BENCHMARK_CAPTURE(BM_CountIf, \
            "count_if_column_major_" #rows "x" #cols, rows, cols, dv::cperf::count_if_column_major)

    // Different dataset sizes
    BENCHMARK_COUNTERS(10, 10);        // Small: 100 elements
    BENCHMARK_COUNTERS(100, 100);      // Medium: 10k elements
    BENCHMARK_COUNTERS(1000, 1000);    // Large: 1M elements
    BENCHMARK_COUNTERS(10000, 1000);   // XLarge: 10M elements
    BENCHMARK_COUNTERS(10000, 10000);  // XXLarge: 100M elements
}

//BENCHMARK_MAIN();
