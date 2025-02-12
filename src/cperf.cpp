/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#include "cperf.h"

#include <stdexcept>

namespace dv::cperf {

int factorial(int n) {
    if (n < 0)
        throw std::invalid_argument("Factorial of negative number is undefined");
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

size_t count_if_range(const Vector2D &vv, Pred pred) {
    size_t sum = 0;
    for (const auto &v : vv) {
        for (const auto &i : v) {
            if (pred(i)) {
                ++sum;
            }
        }
    }
    return sum;
}

size_t count_if_row_major(const Vector2D &vv, Pred pred) {
    size_t sum = 0;
    for (size_t i = 0; i < vv.size(); ++i) {
        for (size_t j = 0; j < vv[i].size(); ++j) {
            if (pred(vv[i][j])) {
                ++sum;
            }
        }
    }
    return sum;
}

size_t count_if_column_major(const Vector2D &vv, Pred pred) {
    size_t sum = 0;
    for (size_t i = 0; i < vv.size(); ++i) {
        for (size_t j = 0; j < vv[i].size(); ++j) {
            if (pred(vv[j][i])) {
                ++sum;
            }
        }
    }
    return sum;
}

} // namespace dv::cperf
