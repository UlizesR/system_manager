#pragma once

#ifndef LMM_OPERATIONS_H
#define LMM_OPERATIONS_H

#include <functional>

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

#endif // LMM_OPERATIONS_H