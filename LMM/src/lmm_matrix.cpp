#include "lmm_matrix.h"
#include "lmm_errors.h"

namespace lmm
{
    Matrix::Matrix() : data_() {}

    Matrix Matrix::transpose() const
    {
        const size_t numRows = data_.size();
        const size_t numCols = cols();

        Matrix result;
        result.data_.resize(numCols, Vector(numRows));

        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < numCols; ++j)
            {
                result.data_[j][i] = data_[i][j];
            }
        }

        return result;
    }

    Matrix Matrix::operator+(const Matrix& other) const
    {
        const size_t numRows = data_.size();
        const size_t numCols = cols();

        if (numRows != other.data_.size() || numCols != other.cols())
        {
            throw std::logic_error(LMM_MATRIX_DIMENSION_ERROR);
        }

        Matrix result;
        result.data_.resize(numRows, Vector(numCols));

        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < numCols; ++j)
            {
                result.data_[i][j] = data_[i][j] + other.data_[i][j];
            }
        }

        return result;
    }

    Matrix Matrix::operator-(const Matrix& other) const
    {
        const size_t numRows = data_.size();
        const size_t numCols = cols();

        if (numRows != other.data_.size() || numCols != other.cols())
        {
            throw std::logic_error(LMM_MATRIX_DIMENSION_ERROR);
        }

        Matrix result;
        result.data_.resize(numRows, Vector(numCols));

        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < numCols; ++j)
            {
                result.data_[i][j] = data_[i][j] - other.data_[i][j];
            }
        }

        return result;
    }

    Matrix Matrix::operator*(float scalar) const
    {
        const size_t numRows = data_.size();
        const size_t numCols = cols();

        Matrix result;
        result.data_.resize(numRows, Vector(numCols));

        for (size_t i = 0; i < numRows; ++i)
        {
            for (size_t j = 0; j < numCols; ++j)
            {
                result.data_[i][j] = data_[i][j] * scalar;
            }
        }

        return result;
    }

    Matrix Matrix::operator*(const Matrix& other) const
    {
        const size_t numRowsA = data_.size();
        const size_t numColsA = cols();
        const size_t numRowsB = other.data_.size();
        const size_t numColsB = other.cols();

        if (numColsA != numRowsB)
        {
            throw std::logic_error(LMM_MATRIX_MULTIPLICATION_ERROR);
        }

        Matrix result;
        result.data_.resize(numRowsA, Vector(numColsB));

        for (size_t i = 0; i < numRowsA; ++i)
        {
            for (size_t j = 0; j < numColsB; ++j)
            {
                float sum = 0.0f;
                for (size_t k = 0; k < numColsA; ++k)
                {
                    sum += data_[i][k] * other.data_[k][j];
                }
                result.data_[i][j] = sum;
            }
        }

        return result;
    }

    Vector Matrix::operator*(const Vector& vec) const
    {
        const size_t numRows = data_.size();
        const size_t numCols = cols();

        if (numCols != vec.length())
        {
            throw std::logic_error(LMM_MATRIX_VECTOR_MULTIPLICATION_ERROR);
        }

        Vector result(numRows);

        for (size_t i = 0; i < numRows; ++i)
        {
            float sum = 0.0f;
            for (size_t j = 0; j < numCols; ++j)
            {
                sum += data_[i][j] * vec[j];
            }
            result[i] = sum;
        }

        return result;
    }

    void Matrix::print() const
    {
        for (size_t i = 0; i < data_.size(); ++i)
        {
            for (size_t j = 0; j < data_[i].length(); ++j)
            {
                std::cout << data_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

} // namespace lmm
