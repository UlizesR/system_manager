#pragma once

#include <iostream>
#include <vector>
#include <QtCore/QVector>

#ifndef LMM_VECTORS_H
#define LMM_VECTORS_H


namespace lmm
{   
    
    typedef QVector<float> Vec;
    
    Vec vec_add(Vec a, Vec b);
    Vec vec_sub(Vec a, Vec b);
    float vec_dot(Vec a, Vec b);
    Vec vec_cross(Vec a, Vec b);
    Vec vec_scale(Vec a, float s);
    float vec_length(Vec a);
    Vec vec_normalize(Vec a);
    
    void vec_print(Vec a);

} // namespace lmm

#endif // LMM_VECTORS_H