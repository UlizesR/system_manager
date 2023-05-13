#pragma once

#include <iostream>
#include <vector>

#ifndef LMM_VECTORS_H
#define LMM_VECTORS_H

#include "lmm_qt.h"

namespace lmm
{   
    
    typedef QVector<float> Vec;

    Vec vec_add(const Vec& a, const Vec& b);
    Vec vec_sub(const Vec& a, const Vec& b);
    float vec_dot(const Vec& a, const Vec& b);
    Vec vec_cross(const Vec& a, const Vec& b);
    Vec vec_scale(const Vec& a, float s);
    float vec_length(const Vec& a);
    Vec vec_normalize(const Vec& a);

    void vec_print(const Vec& a);


} // namespace lmm

#endif // LMM_VECTORS_H