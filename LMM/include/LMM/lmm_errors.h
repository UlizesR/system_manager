#pragma once

#ifndef LMM_ERRORS_H
#define LMM_ERRORS_H

#include <iostream>
#include <string>

namespace lmm
{
    #define LMM_VECTOR_DIMENSION_ERROR  "Dimension of vectors must be equal"
    #define LMM_CROSS_PRODUCT_ERROR     "Cross product is only defined for 3D vectors"
    #define LMM_MATRIX_DIMENSION_ERROR  "Dimension of matrices must be equal"
    #define LMM_OUT_OF_BOUNDS_ERROR     "Index out of bounds"
    #define LMM_MATRIX_SINGULAR_ERROR   "Matrix is singular"
    #define LMM_MATRIX_INVERSION_ERROR  "Matrix is not invertible"
}

#endif // LMM_ERRORS_H