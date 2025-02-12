/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include <cperf.h>
#include <gtest/gtest.h>

TEST(FactorialTest, Zero) { EXPECT_EQ(1, dv::cperf::factorial(0)); }

TEST(FactorialTest, Positive) {
    EXPECT_EQ(1, dv::cperf::factorial(1));
    EXPECT_EQ(2, dv::cperf::factorial(2));
    EXPECT_EQ(6, dv::cperf::factorial(3));
    EXPECT_EQ(40320, dv::cperf::factorial(8));
}

TEST(FactorialTest, Negative) { EXPECT_THROW(dv::cperf::factorial(-1), std::invalid_argument); }


TEST(CountIfTest, CountIfAllTheSame) {
    dv::cperf::Vector2D vv = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    dv::cperf::Pred pred = [](int i) { return i % 2 == 0; };
    EXPECT_EQ(4, dv::cperf::count_if_range(vv, pred));
    EXPECT_EQ(4, dv::cperf::count_if_row_major(vv, pred));
    EXPECT_EQ(4, dv::cperf::count_if_column_major(vv, pred));
}