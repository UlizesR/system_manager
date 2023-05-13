#pragma once

#ifndef LMM_MATRIX_H
#define LMM_MATRIX_H

#include "lmm_vectors.h"

namespace lmm
{
    class Matrix
    {
    public:
        Matrix();                                            // initializes a matrix of size 0
        Matrix(const std::vector<Vector>& data) : data_(data) {} // initializes a matrix

        // Matrix properties
        size_t rows() const { return data_.size(); }                              // returns the number of rows in the matrix
        size_t cols() const { return (data_.empty() ? 0 : data_[0].length()); }   // returns the number of columns in the matrix
        bool isSquare() const { return (rows() == cols()); }                    

        // Matrix operations
        Matrix rref() const;                                // reduced row echelon form
        Matrix transpose() const;                           // transpose of the matrix
        Matrix inverse() const;                             // inverse of the matrix
        float determinant() const;                          // determinant of the matrix
        size_t rank() const;                                // rank of the matrix
        size_t dim() const;                                 // dimension of the matrix
        Vector nullSpace() const;                           // null space of the matrix
        Matrix columnSpace() const;                         // column space of the matrix
        Matrix rowSpace() const;                            // row space of the matrix

        // Matrix element access
        Vector& operator[](size_t index);                   // returns a reference to the row at the specified index
        const Vector& operator[](size_t index) const;       // returns a const reference to the row at the specified index

        // Matrix operations
        Matrix operator+(const Matrix& other) const;        // matrix addition
        Matrix operator-(const Matrix& other) const;        // matrix subtraction
        Matrix operator*(float scalar) const;               // scalar multiplication
        Matrix operator*(const Matrix& other) const;        // matrix multiplication
        Vector operator*(const Vector& vec) const;          // matrix-vector multiplication

        // Matrix printing
        void print() const;

    private:
        std::vector<Vector> data_;
    };
} // namespace lmm

#endif // LMM_MATRIX_H
