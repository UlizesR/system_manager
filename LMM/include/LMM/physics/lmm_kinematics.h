#ifndef LMM_KINEMATICS_H
#define LMM_KINEMATICS_H

#include "lmm_vectors.h"

namespace lmm
{
    namespace physics
    {
        // Equation 1
        // v_f = v_i + a * t
        // float version
        float velocity_f(float v_i, float a, float t);
        // Vector version
        Vec velocity_f(Vec v_i, Vec a, float t);

        // Equation 2
        // x_f = x_i + v_i * t + 0.5 * a * t^2
        // float version
        float displacement(float v_i, float a, float t);
        // Vector version
        Vec displacement(Vec v_i, Vec a, float t);

        // Equation 3
        // v_f^2 = v_i^2 + 2 * a * x_f
        // float version
        float velocity_f_squared(float v_i, float a, float x_f, float x_i);
        // Vector version
        Vec velocity_f_squared(Vec v_i, Vec a, Vec x_f, Vec x_i);

        // Equation 4
        // x_f = x_i + 0.5 * (v_f + v_i) * t
        // float version
        float displacement_2(float v_f, float v_i, float t);
        // Vector version
        Vec displacement_2(Vec v_f, Vec v_i, float t);

        // Equation 5
        // x_f = x_i + v_i * t - 0.5 * a * t^2
        // float version
        float displacement_3(float v_f, float a, float t);
        // Vector version
        Vec displacement_3(Vec v_f, Vec a, float t);
    }
}

#endif // LMM_KINEMATICS_H