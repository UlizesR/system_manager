#include "lmm_matrix.h"
#include "lmm_errors.h"



namespace lmm
{
    Mat mat_add(Mat a, Mat b)
    {
        if (a.size() != b.size()) throw std::invalid_argument(LMM_MATRIX_DIMENSION_ERROR);
        Mat c;
        for (int i = 0; i < a.size(); i++) c.push_back(vec_add(a[i], b[i]));
        return c;
    }

    Mat mat_sub(Mat a, Mat b)
    {
        if (a.size() != b.size()) throw std::invalid_argument(LMM_MATRIX_DIMENSION_ERROR);
        Mat c;
        for (int i = 0; i < a.size(); i++) c.push_back(vec_sub(a[i], b[i]));
        return c;
    }

    Mat mat_scale(Mat a, float s)
    {
        Mat c;
        for (int i = 0; i < a.size(); i++) c.push_back(vec_scale(a[i], s));
        return c;
    }

    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }


    Mat mat_mul(Mat a, Mat b)
    {
        int a_rows = a.size();
        int a_cols = 0;
        if (a_rows > 0) {
            a_cols = a[0].size();
        } else {
            throw std::invalid_argument(LMM_OUT_OF_BOUNDS_ERROR);
        }
        int b_rows = b.size();
        int b_cols = 0;
        if (b_rows > 0) {
            b_cols = b[0].size();
        } else {
            throw std::invalid_argument(LMM_OUT_OF_BOUNDS_ERROR);
        }

        if (a_cols != b_rows) {
            // Dimensions are incompatible, transpose b
            b = mat_transpose(b);
            swap(b_rows, b_cols);
        }
Mat c;
        return c;
    }


    // Vec mat_vec_mul(Mat a, Vec b)
    // {

    // }

    Mat mat_transpose(Mat a)
    {
        int rows = a.size();
        int cols = 0;
        if (rows > 0) {
            cols = a[0].size();
        } else {
            return a;
        }

        Mat result(cols, Vec(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = a[i][j];
            }
        }

        return result;
    }


    Mat mat_inverse(Mat a)
    {
        int rows = a.size();
        int cols = 0;
        if (rows > 0) {
            cols = a[0].size();
        } else {
            return a;
        }

        if (rows != cols) throw std::invalid_argument(LMM_MATRIX_DIMENSION_ERROR);

        Mat result(rows, Vec(cols));
        return result;
    }

    // float mat_determinant(Mat a)
    // {

    // }

    Mat mat_identity(int n)
    {
        Mat result(n, Vec(n));
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
        }
        return result;
    }

}