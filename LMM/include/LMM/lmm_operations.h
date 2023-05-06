#pragma once

#ifndef LMM_OPERATIONS_H
#define LMM_OPERATIONS_H

#include "lmm_func.h"

namespace lmm
{

    float summation(Func f, int lower, int upper);
    float product(Func f, int lower, int upper);
    
}

#endif // LMM_OPERATIONS_H