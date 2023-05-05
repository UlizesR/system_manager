#pragma once

#ifndef LMM_ERRORS_H
#define LMM_ERRORS_H

#include <iostream>
#include <string>

namespace lmm
{
    #define LMM_VECTOR_DIMENSION_ERROR "Dimension of vectors must be equal"
    #define LMM_CROSS_PRODUCT_ERROR "Cross product is only defined for 3D vectors"
    #define LMM_MATRIX_DIMENSION_ERROR "Dimension of matrices must be equal"
    #define LMM_OUT_OF_BOUNDS_ERROR "Index out of bounds"
}

#endif // LMM_ERRORS_H