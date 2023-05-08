#pragma once

#ifndef LMM_FUNCTIONS_H
#define LMM_FUNCTIONS_H

#include <functional>
#include <raylib.h>

namespace lmm
{
    typedef std::function<double(double)> Func;

    float summation(Func f, int lower, int upper);
    float product(Func f, int lower, int upper);

    int factorial(int n);
    double permutation(int n, int k);
    double combination(int n, int k);
    float binomial(int n, int k, float p);
    
    
}

#endif // LMM_FUNCTIONS_H