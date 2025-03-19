#include "geometry/geometry.hpp"
#include "Toolbox.hpp"
#include <cmath>

namespace ml
{
    // vector
    template<size_t L>
    vec<L> normalize(const vec<L> &vector)
    {
        float length = 0;
        for (size_t i = 0; i < L; i++)
            length += powf(vector[i], 2);
        length = sqrt(length);
        if (length == 0)
            throw(std::runtime_error("normalization of a vector: length = 0, error"));
        
        vec<L> result;
        for (size_t i = 0; i < L; i++)
            result[i] = vector[i] / length;
        return (result);
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

    template<size_t L>
    float dotProduct(const vec<L> &vectorA, const vec<L> &vectorB)
    {
        float result = 0;
        for (size_t i = 0; i < L; i++)
            result += vectorA[i] * vectorB[i];
        return (result);
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

    mat4 rotate(const vec4 &quat) //@todo create a struct quat
    {
        mat4 result;
        result[0][0] = 2 * (pow(quat.w, 2) + pow(quat.x, 2)) - 1;
        result[0][1] = 2 * (quat.x * quat.y - quat.w * quat.z);
        result[0][2] = 2 * (quat.x * quat.z + quat.w * quat.y);
        result[0][3] = 0;

        result[1][0] = 2 * (quat.x * quat.y + quat.w * quat.z);
        result[1][1] = 2 * (pow(quat.w, 2) + pow(quat.y, 2)) - 1;
        result[1][2] = 2 * (quat.y * quat.z - quat.w * quat.x);
        result[1][3] = 0;

        result[2][0] = 2 * (quat.x * quat.z - quat.w * quat.y);
        result[2][1] = 2 * (quat.y * quat.z + quat.w * quat.x);
        result[2][2] = 2 * (pow(quat.w, 2) + pow(quat.z, 2)) - 1;
        result[2][3] = 0;

        result[3][0] = 0;
        result[3][1] = 0;
        result[3][2] = 0;
        result[3][3] = 1;

        return (result);
    }

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far)
    {   
        float tangent = tanf(Toolbox::DegToRad(fov / 2)); //@todo put it in this lib
        float halfHeight = near * tangent;
        float halfWidth = halfHeight * aspect;
        
        float left = halfWidth;
        float right = -halfWidth;
        float top = halfHeight;
        float bottom = -halfHeight;
        
        mat4 result;

        result[0][0] = (2 * near) / (right - left);
        result[0][1] = 0;
        result[0][2] = (right + left) / (right - left);
        result[0][3] = 0;

        result[1][0] = 0;
        result[1][1] = (2 * near) / (top - bottom);
        result[1][2] = (top + bottom) / (top - bottom);
        result[1][3] = 0;

        result[2][0] = 0;
        result[2][1] = 0;
        result[2][2] = (-(far + near)) / (far - near);
        result[2][3] = (-2 * far * near) / (far - near);

        result[3][0] = 0;
        result[3][1] = 0;
        result[3][2] = -1;
        result[3][3] = 0;

        return (result);
    }

    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector)
    {
        vec3 front = normalize(position - target);
        vec3 right = normalize(crossProduct(initialUpVector, front));
        vec3 up = normalize(crossProduct(front, right));

        vec3 translation;
        translation[0] = dotProduct(position, right);
        translation[1] = dotProduct(position, up);
        translation[2] = dotProduct(position, front);

        mat4 result;
        result[0][0] = right.x;
        result[0][1] = up.x;
        result[0][2] = front.x;
        result[0][3] = 0;

        result[1][0] = right.y;
        result[1][1] = up.y;
        result[1][2] = front.y;
        result[1][3] = 0;

        result[2][0] = right.z;
        result[2][1] = up.z;
        result[2][2] = front.z;
        result[2][3] = 0;

        result[3][0] = -translation.x;
        result[3][1] = -translation.y;
        result[3][2] = -translation.z;
        result[3][3] = 1;

        return (result);
    }
}