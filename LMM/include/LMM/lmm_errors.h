#pragma once

#ifndef LMM_ERRORS_H
#define LMM_ERRORS_H

#include <iostream>
#include <string>

namespace lmm
{
    // Vector error messages
    #define LMM_VECTOR_DIMENSION_ERROR  "Dimension mismatch: vectors must have the same size"
    #define LMM_CROSS_PRODUCT_ERROR     "Invalid Operation: Cross product only valid in 3 Dimensions"
    #define LMM_ZERO_VECTOR_ERROR       "Invalid Calculation: Zero vector used"
    #define LMM_OUT_OF_BOUNDS_ERROR     "Out of Bounds: Index out of range"
}

#endif // LMM_ERRORS_H