#include "Matrix/geometry/geometry.hpp"
#include <cmath>

namespace ml
{
    // vector
    template<size_t L>
    inline vec<L> normalize(const vec<L> &vector)
    {
        float l = length(vector);
        if (l == 0)
            throw(std::runtime_error("normalization of a vector: length = 0, error"));
        
        vec<L> result;
        for (size_t i = 0; i < L; i++)
            result[i] = vector[i] / l;
        return (result);
    }

    inline vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB)
    {
        vec3 vectorAB(vectorB.x - vectorA.x, vectorB.y - vectorA.y, vectorB.z - vectorA.z);

        return (vec3(
            vectorA.y * vectorAB.z - vectorA.z * vectorAB.y,
            vectorA.z * vectorAB.x - vectorA.x * vectorAB.z,
            vectorA.x * vectorAB.y - vectorA.y * vectorAB.x
        ));
    }

    template<size_t L>
    inline float dotProduct(const vec<L> &vectorA, const vec<L> &vectorB)
    {
        float result = 0;
        for (size_t i = 0; i < L; i++)
            result += vectorA[i] * vectorB[i];
        return (result);
    }
    
    template<size_t L>
    inline float length(const vec<L> &vector)
    {
        float length = 0;
        for (size_t i = 0; i < L; i++)
            length += powf(vector[i], 2);
        length = sqrt(length);

        return (length);
    }

    // matrix
    inline mat4 translate(const mat4 &matrix, const vec3 &vector)
    {
        mat4 translation;
        translation.identity();
        translation[0][3] = vector.x; //@todo: create a constructor for vec4 taking (vec3, w) parameters
        translation[1][3] = vector.y; //@todo: create a constructor for vec4 taking (vec3, w) parameters
        translation[2][3] = vector.z; //@todo: create a constructor for vec4 taking (vec3, w) parameters
        return (matrix * translation);
    }

    inline mat4 scale(const mat4 &matrix, const vec3 &vector)
    {
        mat4 scale;
        scale.identity();
        for (size_t i = 0; i < 3; i++)
        scale[i][i] = vector[i];
        return (matrix * scale);
    }

    inline mat4 rotate(const mat4 &matrix, float angle, const vec3 &axis)
    {
        angle = radians(angle); //@todo put it in this lib

        float cosAngle = cosf(angle);
        float sinAngle = sinf(angle);
        vec3 axisN = normalize(axis);

        mat4 rotation;
        rotation[0][0] = cosAngle + pow(axisN.x, 2) * (1 - cosAngle);
        rotation[1][0] = axisN.x * axisN.y * (1 - cosAngle) - axisN.z * sinAngle;
        rotation[2][0] = axisN.x * axisN.z * (1 - cosAngle) + axisN.y * sinAngle;
        rotation[3][0] = 0;

        rotation[0][1] = axisN.y * axisN.x * (1 - cosAngle) + axisN.z * sinAngle;
        rotation[1][1] = cosAngle + pow(axisN.y, 2) * (1 - cosAngle);
        rotation[2][1] = axisN.y * axisN.z * (1 - cosAngle) - axisN.x * sinAngle;
        rotation[3][1] = 0;

        rotation[0][2] = axisN.z * axisN.x * (1 - cosAngle) - axisN.y * sinAngle;
        rotation[1][2] = axisN.z * axisN.y * (1 - cosAngle) + axisN.x * sinAngle;
        rotation[2][2] = cosAngle + pow(axisN.z, 2) * (1 - cosAngle);
        rotation[3][2] = 0;

        rotation[0][3] = 0;
        rotation[1][3] = 0;
        rotation[2][3] = 0;
        rotation[3][3] = 1;

        return (matrix * rotation);
    }

    inline mat4 rotate(const mat4 &matrix, const vec4 &quat) //@todo create a struct quat
    {
        return (matrix * toMat(quat));
    }

    inline mat4 toMat(const vec4 &quat) //@todo create a struct quat
    {
        mat4 matrix;
        matrix[0][0] = 2 * (pow(quat.w, 2) + pow(quat.x, 2)) - 1;
        matrix[0][1] = 2 * (quat.x * quat.y - quat.w * quat.z);
        matrix[0][2] = 2 * (quat.x * quat.z + quat.w * quat.y);
        matrix[0][3] = 0;

        matrix[1][0] = 2 * (quat.x * quat.y + quat.w * quat.z);
        matrix[1][1] = 2 * (pow(quat.w, 2) + pow(quat.y, 2)) - 1;
        matrix[1][2] = 2 * (quat.y * quat.z - quat.w * quat.x);
        matrix[1][3] = 0;

        matrix[2][0] = 2 * (quat.x * quat.z - quat.w * quat.y);
        matrix[2][1] = 2 * (quat.y * quat.z + quat.w * quat.x);
        matrix[2][2] = 2 * (pow(quat.w, 2) + pow(quat.z, 2)) - 1;
        matrix[2][3] = 0;

        matrix[3][0] = 0;
        matrix[3][1] = 0;
        matrix[3][2] = 0;
        matrix[3][3] = 1;

        return (matrix);
    }

    // 2D
    inline mat4 ortho(float left, float right, float bottom, float top, float near, float far)
    {
        (void)near;
        (void)far;
        mat4 result;
        result.identity();

		result[0][0] = 2 / (right - left);
		result[1][1] = 2 / (top - bottom);
		result[2][2] = -1;
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);

		return result;
    }

    // 3D
    inline mat4 perspective(float fov, float aspect, float near, float far)
    {   
        float tangent = tanf(degrees(fov) / 2); //@todo put it in this lib
        
        mat4 result;

        result[0][0] = 1 / (aspect * tangent);
        result[0][1] = 0;
        result[0][2] = 0;
        result[0][3] = 0;

        result[1][0] = 0;
        result[1][1] = 1 / tangent;
        result[1][2] = 0;
        result[1][3] = 0;

        result[2][0] = 0;
        result[2][1] = 0;
        result[2][2] = -((far + near) / (far - near));
        result[2][3] = -((2 * far * near) / (far - near));

        result[3][0] = 0;
        result[3][1] = 0;
        result[3][2] = -1;
        result[3][3] = 0;

        return (result);
    }

    inline mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector)
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
        result[1][0] = up.x;
        result[2][0] = front.x;
        result[3][0] = 0;

        result[0][1] = right.y;
        result[1][1] = up.y;
        result[2][1] = front.y;
        result[3][1] = 0;

        result[0][2] = right.z;
        result[1][2] = up.z;
        result[2][2] = front.z;
        result[3][2] = 0;

        result[0][3] = -translation.x;
        result[1][3] = -translation.y;
        result[2][3] = -translation.z;
        result[3][3] = 1;

        return (result);
    }

    // math
    inline float degrees(float radians)
    {
        return (roundf(radians * (180 / M_PI) * 100000) / 100000);
    }

    inline float radians(float degrees)
    {
        return (roundf(degrees * (M_PI / 180) * 100000) / 100000);
    }

    inline float clamp(float value, float min, float max)
    {
        if (value < min)
            return (min);
        else if (value > max)
            return (max);
        else
            return (value);
    }
}