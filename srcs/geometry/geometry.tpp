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

    mat4 rotate(float angle, const vec3 &axis)
    {
        float cosAngle = cosf(angle);
        float sinAngle = sinf(angle);
        vec3 axisN = normalize(axis);

        mat4 result;
        result[0][0] = cosAngle + pow(axisN.x, 2) * (1 - cosAngle);
        result[0][1] = axisN.x * axisN.y * (1 - cosAngle) - axisN.z * sinAngle;
        result[0][2] = axisN.x * axisN.z * (1 - cosAngle) - axisN.y * sinAngle;
        result[0][3] = 0;

        result[1][0] = axisN.y * axisN.x * (1 - cosAngle) - axisN.z * sinAngle;
        result[1][1] = cosAngle + pow(axisN.y, 2) * (1 - cosAngle);
        result[1][2] = axisN.y * axisN.z * (1 - cosAngle) - axisN.x * sinAngle;
        result[1][3] = 0;

        result[2][0] = axisN.z * axisN.x * (1 - cosAngle) - axisN.y * sinAngle;
        result[2][1] = axisN.z * axisN.y * (1 - cosAngle) - axisN.x * sinAngle;
        result[2][2] = cosAngle + pow(axisN.z, 2) * (1 - cosAngle);
        result[2][3] = 0;

        result[3][0] = 0;
        result[3][1] = 0;
        result[3][2] = 0;
        result[3][3] = 1;

        return (result);
    }

    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);
}