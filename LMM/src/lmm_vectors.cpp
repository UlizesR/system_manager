#include "lmm_vectors.h"
#include "lmm_errors.h"
#include <cmath>
#include <iostream>
#include <iomanip>

namespace lmm {
    Vec vec_add(Vec a, Vec b)
    {
        if (a.size() != b.size()) throw std::invalid_argument(LMM_VECTOR_DIMENSION_ERROR);
        Vec c;
        for (int i = 0; i < a.size(); i++) c.push_back(a[i] + b[i]);
        return c;
    }

    Vec vec_sub(Vec a, Vec b)
    {
        if (a.size() != b.size()) throw std::invalid_argument(LMM_VECTOR_DIMENSION_ERROR);
        Vec c;
        for (int i = 0; i < a.size(); i++) c.push_back(a[i] - b[i]);
        return c;
    }

    float vec_dot(Vec a, Vec b)
    {   
        if (a.size() != b.size()) throw std::invalid_argument(LMM_VECTOR_DIMENSION_ERROR);
        float c = 0;
        for (int i = 0; i < a.size(); i++) c += a[i] * b[i];
        return c;
    }

    Vec vec_cross(Vec a, Vec b)
    {
        if (a.size() != 3 || b.size() != 3) throw std::invalid_argument(LMM_CROSS_PRODUCT_ERROR);
        Vec c;
        c.push_back(a[1] * b[2] - a[2] * b[1]);
        c.push_back(a[2] * b[0] - a[0] * b[2]);
        c.push_back(a[0] * b[1] - a[1] * b[0]);
        return c;
    }

    Vec vec_scale(Vec a, float s)
    {
        Vec c;
        for (int i = 0; i < a.size(); i++) c.push_back(a[i] * s);
        return c;
    }

    float vec_length(Vec a)
    {
        float length = 0;
        for (int i = 0; i < a.size(); i++) length += a[i] * a[i];
        return sqrt(length);
    }

    Vec vec_normalize(Vec a)
    {
        float length = vec_length(a);
        Vec c;
        for (int i = 0; i < a.size(); i++) c.push_back(a[i] / length);
        return c;
    }

    void vec_print(Vec a)
    {
        for (int i = 0; i < a.size(); i++) std::cout << "| " << a[i] << " |\n"; 
        std::cout << std::endl;
    }
}