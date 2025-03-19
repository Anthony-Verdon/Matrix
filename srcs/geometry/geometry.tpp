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

    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB)
    {
        vec3 vectorAB(vectorB.x - vectorA.x, vectorB.y - vectorA.y, vectorB.z - vectorA.z);

        return (vec3(
            vectorA.y * vectorAB.z - vectorA.z * vectorAB.y,
            vectorA.z * vectorAB.x - vectorA.x * vectorAB.z,
            vectorA.x * vectorAB.y - vectorA.y * vectorAB.x
        ));
    }

    float dotProduct(const vec3 &vectorA, const vec3 &vectorB)
    {
        return (vectorA.x * vectorB.x + vectorA.y * vectorB.y + vectorA.z * vectorB.z);
    }
    
    // matrix
    mat4 translate(const vec3 &vector)
    {
        mat4 result;
        result.identity();
        result[3] = vec4(vector.x, vector.y, vector.z, 1); //@todo: create a constructor for vec4 taking (vec3, w) parameters
        return (result);
    }

    mat4 scale(const vec3 &vector)
    {
        mat4 result;
        result.identity();
        for (size_t i = 0; i < 3; i++)
            result[i][i] = vector[i];
        return (result);
    }

    mat4 rotate(const mat4 &matrix, float angle, const vec3 &axis);
    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);
}