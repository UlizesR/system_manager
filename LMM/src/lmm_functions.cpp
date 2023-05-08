#include "lmm_functions.h"
#include <cmath>

namespace lmm
{
    float summation(Func f, int lower, int upper)
    {
        float result = 0.0f;
        for (int i = lower; i <= upper; ++i)
        {
            result += f(i);
        }
        return result;
    }

    float product(Func f, int lower, int upper)
    {
        float result = 1.0f;
        for (int i = lower; i <= upper; ++i)
        {
            result *= f(i);
        }
        return result;
    }

    int factorial(int n)
    {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }

    double permutation(int n, int k)
    {
        return (double) factorial(n) / factorial(n - k);
    }

    double combination(int n, int k)
    {
        return permutation(n, k) / factorial(k);
    }

    float binomial(int n, int k, float p)
    {
        float q = 1.0f - p;
        return combination(n, k) * pow(p, k) * pow(q, n - k);
    }

    

}
