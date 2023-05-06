#include "lmm_operations.h"

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
}
