#pragma once

#include "Matrix/mat/mat.hpp"
#include "Matrix/vec/vec.hpp"

namespace ml
{
    // vector
    template<size_t L>
    vec<L> normalize(const vec<L> &vector);
    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB);
    template<size_t L>
    float dotProduct(const vec<L> &vectorA, const vec<L> &vectorB);
    
    // matrix
    mat4 translate(const mat4 &matrix, const vec3 &vector);
    mat4 scale(const mat4 &matrix, const vec3 &vector);
    mat4 rotate(const mat4 &matrix, float angle, const vec3 &axis);
    mat4 rotate(const mat4 &matrix, const vec4 &quat);
    mat4 toMat(const vec4 &quat);

    // 2D
    mat4 ortho(float left, float right, float bottom, float top, float near, float far);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);

    // math
    float degrees(float radians);
    float radians(float degrees);
    float clamp(float value, float min, float max);
}

#include "Matrix/geometry/geometry.tpp"