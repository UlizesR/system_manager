#include "lmm_kinematics.h"

namespace lmm
{
    namespace physics
    {
        // Equation 1
        // v_f = v_i + a * t
        // float version
        float velocity_f(float v_i, float a, float t)
        {   
            return v_i + a * t;
        }
        // Vector version
        Vec velocity_f(Vec v_i, Vec a, float t)
        {
            return vec_add(v_i, vec_scale(a, t));
        }

        // Equation 2
        // x_f = x_i + v_i * t + 0.5 * a * t^2
        // float version
        float displacement(float v_i, float a, float t)
        {
            return v_i * t + 0.5 * a * t * t;
        }
        // Vector version
        Vec displacement(Vec v_i, Vec a, float t)
        {
            return vec_add(vec_scale(v_i, t), vec_scale(a, 0.5 * t * t));
        }

        // Equation 3
        // v_f^2 = v_i^2 + 2 * a * x_f
        // float version
        float velocity_f_squared(float v_i, float a, float x_f, float x_i)
        {
            return v_i * v_i + 2 * a * (x_f - x_i);
        }
        // Vector version
        Vec velocity_f_squared(Vec v_i, Vec a, Vec x_f, Vec x_i)
        {
            Vec dx = vec_sub(x_f, x_i);
            return dx;
        }

        // Equation 4
        // x_f = x_i + 0.5 * (v_f + v_i) * t
        // float version
        float displacement_2(float v_f, float v_i, float t)
        {
            return 0.5 * (v_f + v_i) * t;
        }
        // Vector version
        Vec displacement_2(Vec v_f, Vec v_i, float t)
        {
            return vec_scale(vec_add(v_f, v_i), 0.5 * t);
        }

        // Equation 5
        // x_f = x_i + v_f * t - 0.5 * a * t^2
        // float version
        float displacement_3(float v_f, float a, float t)
        {
            return v_f * t - 0.5 * a * t * t;
        }
        // Vector version
        Vec displacement_3(Vec v_f, Vec a, float t)
        {
            return vec_sub(vec_scale(v_f, t), vec_scale(a, 0.5 * t * t));
        }
    }
}