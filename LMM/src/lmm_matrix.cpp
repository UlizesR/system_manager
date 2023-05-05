#include "lmm_matrix.h"
#include "lmm_errors.h"
 #include <thread>
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

        Mat c(a_rows, Vec(b_cols));

        int num_threads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(num_threads);
        int chunk_size = a_rows / num_threads;
        int remainder = a_rows % num_threads;
        int start = 0;
        for (int i = 0; i < num_threads; i++) {
            int end = start + chunk_size;
            if (i < remainder) {
                end++;
            }
            threads[i] = std::thread([&a, &b, &c, a_cols, b_cols](int start, int end) {
                for (int i = start; i < end; i++) {
                    for (int j = 0; j < b_cols; j++) {
                        float sum = 0.0f;
                        for (int k = 0; k < a_cols; k++) {
                            sum += a[i][k] * b[k][j];
                        }
                        c[i][j] = sum;
                    }
                }
            }, start, end);
            start = end;
        }
        for (auto& thread : threads) {
            thread.join();
        }

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


    Mat mat_identity(int n)
    {
        Mat result(n, Vec(n));
        for (int i = 0; i < n; i++) {
            result[i][i] = 1;
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

        // Create an identity matrix
        Mat I = mat_identity(rows);

        // Perform LU factorization
        for (int k = 0; k < rows; k++) {
            for (int i = k + 1; i < rows; i++) {
                double factor = a[i][k] / a[k][k];
                for (int j = k + 1; j < rows; j++) {
                    a[i][j] -= factor * a[k][j];
                }
                a[i][k] = factor;
            }
        }

        // Solve for inverse using forward and backward substitution
        for (int k = 0; k < rows; k++) {
            for (int j = 0; j < cols; j++) {
                double sum1 = 0;
                double sum2 = 0;
                for (int i = 0; i < k; i++) {
                    sum1 += a[k][i] * I[i][j];
                }
                I[k][j] = (j == k) ? 1 - sum1 : -sum1;
                for (int i = k + 1; i < rows; i++) {
                    sum2 += a[k][i] * I[i][j];
                }
                I[k][j] /= a[k][k];
                I[k][j] -= sum2 / a[k][k];
            }
        }

        return I;
    }



    float mat_determinant(Mat a)
    {
        int n = a.size();
        int sign = 1;
        float det = 1;

        // Perform LU decomposition with partial pivoting
        for (int k = 0; k < n; k++) {
            int p = k;
            for (int i = k + 1; i < n; i++) {
                if (fabs(a[i][k]) > fabs(a[p][k])) {
                    p = i;
                }
            }
            if (p != k) {
                swap(a[k], a[p]);
                sign *= -1;
            }
            if (fabs(a[k][k]) < 1e-10) {
                return 0;
            }
            det *= a[k][k];
            for (int i = k + 1; i < n; i++) {
                float factor = a[i][k] / a[k][k];
                for (int j = k + 1; j < n; j++) {
                    a[i][j] -= factor * a[k][j];
                }
                a[i][k] = factor;
            }
        }

        return det * sign;
    }

}