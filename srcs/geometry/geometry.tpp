#include "geometry/geometry.hpp"
#include <cmath>

namespace ml
{
    // vector
    vec3 normalize(const vec3 &vector)
    {
        float length = sqrt(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
        if (length == 0)
            throw(std::runtime_error("normalization of a vector: length = 0, error"));
        
        return (vec3(vector.x / length, vector.y / length, vector.z / length));
    }

    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB);
    float dotProduct(const vec3 &vectorA, const vec3 &vectorB);
    
    // matrix
    mat4 translate(const mat4 &matrix, const vec3 &vector);
    mat4 scale(const mat4 &matrix, const vec3 &vector);
    mat4 rotate(const mat4 &matrix, float angle, const vec3 &axis);
    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);
}