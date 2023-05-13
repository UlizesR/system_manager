#pragma once

#include <iostream>
#include <vector>

#ifndef LMM_VECTORS_H
#define LMM_VECTORS_H

#include "lmm_qt.h"

namespace lmm
{   
    class Vector
    {
        public:
            Vector();                                                               // initializes a vector of size 0
            Vector(const QVector<float>& vec) : data(vec) {}                        // initializes a vector
            Vector(const QVector<float>& vec) : data(vec.begin(), vec.end()) {}     // copies a vector
            Vector(const QVector<float>& tail, const QVector<float>& head);         // creates a vector from two points

            // Vector properties
            float length() const;                           // returns the length of the vector
            float normalize() const;                        // normalizes the vector
            float dot(const Vector& vec) const;             // dot product
            // cross product only works in 3 Dimensions
            Vector cross(const Vector& vec) const;          // cross product

            float angle() const;                            // returns the angle between the vector and the x-axis
            float angle(const Vector& vec) const;           // returns the angle between two vectors

            Vector projection(const Vector& vec) const;     // returns the projection of the vector onto another vector

            void print() const;                             // prints the vector

            // Operator overloading
            // Element access
            float& operator[](int index);                   // returns a reference to the element at the specified index
            const float& operator[](int index) const;       // returns a const reference to the element at the specified index

            // Vector operations
            Vector operator+(const Vector& vec) const;      // vector addition
            Vector operator-(const Vector& vec) const;      // vector subtraction
            Vector operator*(float scalar) const;           // scalar multiplication
            Vector operator/(float scalar) const;           // scalar division
            float operator*(const Vector& vec) const;       // dot product

        private:
            QVector<float> data;
    };
} // namespace lmm

#endif // LMM_VECTORS_H