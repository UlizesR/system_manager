#include "lmm_vectors.h"
#include "lmm_errors.h"
#include <cmath>

namespace lmm
{

    Vector::Vector(const QVector<float>& tail, const QVector<float>& head)
    {
        if (tail.size() != head.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }

        data.reserve(tail.size());
        for (size_t i = 0; i < tail.size(); ++i)
        {
            data.emplace_back(head[i] - tail[i]);
        }
    }

    // Vector properties
    float Vector::length() const
    {
        float sumOfSquares = 0.0f;
        for (const auto& value : data) sumOfSquares += value * value;
        return std::sqrt(sumOfSquares);
    }

    float Vector::normalize() const
    {
        float vecLength = length();
        if (vecLength == 0.0f)
        {
            throw std::logic_error("Normalization of zero vector");
        }
        return 1 / vecLength;
    }


    float Vector::dot(const Vector& vec) const
    {
        if (data.size() != vec.data.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }
        float dotProduct = 0.0f;
        for (size_t i = 0; i < data.size(); ++i)
        {
            dotProduct += data[i] * vec.data[i];
        }
        return dotProduct;
    }

    Vector Vector::cross(const Vector& vec) const
    {
        if (data.size() != 3 || vec.data.size() != 3)
        {
            throw std::logic_error(LMM_CROSS_PRODUCT_ERROR);
        }
        const float x1 = data[0];
        const float y1 = data[1];
        const float z1 = data[2];
        const float x2 = vec.data[0];
        const float y2 = vec.data[1];
        const float z2 = vec.data[2];
        return Vector({ y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2 });
    }

    float Vector::angle() const
    {
        const float x = data[0];
        const float y = data[1];
        return std::atan2(y, x);
    }

    float Vector::angle(const Vector& vec) const
    {
        const float dotProduct = dot(vec);
        const float thisLength = length();
        const float vecLength = vec.length();
        if (thisLength == 0.0f || vecLength == 0.0f)
        {
            throw std::logic_error(LMM_ZERO_VECTOR_ERROR);
        }
        return std::acos(dotProduct / (thisLength * vecLength));
    }

    Vector Vector::projection(const Vector& vec) const
    {
        if (data.size() != vec.data.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }
        const float dotProduct = dot(vec);
        const float vecLengthSquared = vec.length() * vec.length();
        if (vecLengthSquared == 0.0f)
        {
            throw std::logic_error(LMM_ZERO_VECTOR_ERROR);
        }
        const float scalar = dotProduct / vecLengthSquared;
        return vec * scalar;
    }

    void Vector::print() const
    {
        for (const auto& value : data)
        {
            std::cout << "| " << value << " |\n";
        }
        std::cout << std::endl;
    }

    // Operator overloading
    // Element access
    float& Vector::operator[](int index)
    {
        if (index < 0 || static_cast<size_t>(index) >= data.size())
        {
            throw std::out_of_range(LMM_OUT_OF_BOUNDS_ERROR);
        }
        return data[index];
    }

    const float& Vector::operator[](int index) const
    {
        if (index < 0 || static_cast<size_t>(index) >= data.size())
        {
            throw std::out_of_range(LMM_OUT_OF_BOUNDS_ERROR);
        }
        return data[index];
    }

    // Vector operations
    Vector Vector::operator+(const Vector& vec) const
    {
        if (data.size() != vec.data.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }
        Vector result(*this);
        for (size_t i = 0; i < data.size(); ++i)
        {
            result.data[i] += vec.data[i];
        }
        return result;
    }

    Vector Vector::operator-(const Vector& vec) const
    {
        if (data.size() != vec.data.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }
        Vector result(*this);
        for (size_t i = 0; i < data.size(); ++i)
        {
            result.data[i] -= vec.data[i];
        }
        return result;
    }

    Vector Vector::operator*(float scalar) const
    {
        Vector result(*this);
        for (auto& value : result.data)
        {
            value *= scalar;
        }
        return result;
    }

    Vector Vector::operator/(float scalar) const
    {
        if (scalar == 0.0f)
        {
            throw std::logic_error(LMM_ZERO_VECTOR_ERROR);
        }
        Vector result(*this);
        for (auto& value : result.data)
        {
            value /= scalar;
        }
        return result;
    }

    float Vector::operator*(const Vector& vec) const
    {
        if (data.size() != vec.data.size())
        {
            throw std::logic_error(LMM_VECTOR_DIMENSION_ERROR);
        }
        float dotProduct = 0.0f;
        for (size_t i = 0; i < data.size(); ++i)
        {
            dotProduct += data[i] * vec.data[i];
        }
        return dotProduct;
    }
} // namespace lmm
