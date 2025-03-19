#pragma once

#include "mat/mat.hpp"
#include "vec/vec.hpp"

namespace ml
{
    // vector
    vec3 normalize(const vec3 &vector);
    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB);
    float dotProduct(const vec3 &vectorA, const vec3 &vectorB);
    
    // matrix
    mat4 translate(const vec3 &vector);
    mat4 scale(const mat4 &matrix, const vec3 &vector);
    mat4 rotate(const mat4 &matrix, float angle, const vec3 &axis);
    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);
}

#include "geometry/geometry.tpp"