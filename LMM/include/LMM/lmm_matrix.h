#pragma once 

#ifndef LMM_MATRIX_H
#define LMM_MATRIX_H

#include "lmm_vectors.h"

namespace lmm 
{
    typedef std::vector<Vec> Mat;

    Mat mat_add(Mat a, Mat b);
    Mat mat_sub(Mat a, Mat b);
    Mat mat_scale(Mat a, float s);
    Mat mat_mul(Mat a, Mat b);
    Vec mat_vec_mul(Mat a, Vec b);
    Mat mat_transpose(Mat a);
    Mat mat_inverse(Mat a);
    float mat_determinant(Mat a);
    Mat mat_identity(int n);

    Mat mat_rref(Mat a);

    int mat_rank(Mat a);
    int mat_dim(Mat a);
    Vec mat_null(Mat a);
    Mat mat_col(Mat a);
    Mat mat_row(Mat a);

    void mat_print(Mat a);
}

#endif // LMM_MATRIX_H