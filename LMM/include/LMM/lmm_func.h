#pragma once

#ifndef LMM_FUNC_H
#define LMM_FUNC_H

#include <functional>

namespace lmm
{
    typedef std::function<double(double)> Func;
}

#endif // LMM_FUNC_H