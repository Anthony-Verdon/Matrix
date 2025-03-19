#pragma once

#include "mat/mat.hpp"
#include "vec/vec.hpp"

namespace ml
{
    // vector
    template<size_t L>
    vec<L> normalize(const vec<L> &vector);
    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB);
    template<size_t L>
    float dotProduct(const vec<L> &vectorA, const vec<L> &vectorB);
    
    // matrix
    mat4 translate(const vec3 &vector);
    mat4 scale(const vec3 &vector);
    mat4 rotate(float angle, const vec3 &axis);
    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);
}

#include "geometry/geometry.tpp"