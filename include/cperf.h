/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg== 
 */

#ifndef __DV_INCLUDE_CPERF_H__
#define __DV_INCLUDE_CPERF_H__

#include <vector>
#include <functional>
namespace dv::cperf {
    int factorial(int n);

    using Vector = std::vector<int>;
    using Vector2D = std::vector<Vector>;
    using Pred = std::function<bool(int)>;
    /*
     * Count all elements matching predicate
     */
    size_t count_if_range(const Vector2D &vv, Pred pred);        // Using range-based for loops
    size_t count_if_row_major(const Vector2D &vv, Pred pred);    // Row-major traversal
    size_t count_if_column_major(const Vector2D &vv, Pred pred); // Column-major traversal
} // namespace dv::cperf

#endif // __DV_INCLUDE_CPERF_H__
