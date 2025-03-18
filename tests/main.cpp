#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "vec/vec.hpp"
#include "matrix/matrix.hpp"

TEST_CASE("vector: instantiation")
{
    SUBCASE("no argument")
    {
        vec2 vector2;
        vec3 vector3;
        vec4 vector4;
        vec<5> vector5;
    }
    SUBCASE("arguments")
    {
        vec2 vector2(1, 2);
        for (int i = 0; i < 2; i++)
            CHECK(vector2[i] == (i + 1));
        vec3 vector3(1, 2, 3);
        for (int i = 0; i < 3; i++)
            CHECK(vector3[i] == (i + 1));
        vec4 vector4(1, 2, 3, 4);
        for (int i = 0; i < 4; i++)
            CHECK(vector4[i] == (i + 1));
        vec<5> vector5(1, 2, 3, 4, 5);
        for (int i = 0; i < 5; i++)
            CHECK(vector5[i] == (i + 1));
    }
    SUBCASE("copy")
    {
        {
            vec<2> vector2(1, 2);
            vec2 vec2Copy(vector2);
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            vec2 vector2(1, 2);
            vec2 vec2Copy(vector2);
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            vec<3> vector3(1, 2, 3);
            vec3 vec3Copy(vector3);
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            vec3 vector3(1, 2, 3);
            vec3 vec3Copy(vector3);
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            vec<4> vector4(1, 2, 3, 4);
            vec4 vec4Copy(vector4);
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            vec4 vector4(1, 2, 3, 4);
            vec4 vec4Copy(vector4);
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            vec<5> vector5(1, 2, 3, 4, 5);
            vec<5> vec5Copy(vector5);
            for (int i = 0; i < 5; i++)
                CHECK(vec5Copy[i] == (i + 1));
        }
    }
}
TEST_CASE("vector: operators")
{
    SUBCASE("operator=")
    {
        {
            vec<2> vector2(1, 2);
            vec2 vec2Copy = vector2;
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            vec<3> vector3(1, 2, 3);
            vec3 vec3Copy = vector3;
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            vec<4> vector4(1, 2, 3, 4);
            vec4 vec4Copy = vector4;
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            vec<5> vector5(1, 2, 3, 4, 5);
            vec<5> vec5Copy = vector5;
            for (int i = 0; i < 5; i++)
                CHECK(vec5Copy[i] == (i + 1));
        }
    }
    SUBCASE("operator[]")
    {
        vec<5> vector5(1, 2, 3, 4, 5);
        for (int i = 0; i < 5; i++)
            CHECK(vector5[i] == (i + 1));
    }
    SUBCASE("operator==")
    {
        {
            vec<5> vector5(1, 2, 3, 4, 5);
            vec<5> vec5Copy = vector5;
            CHECK(vector5 == vec5Copy);
        }
        {
            vec<5> vectorA(1, 2, 3, 4, 5);
            vec<5> vectorB(6, 7, 8, 9, 10);
            CHECK_FALSE(vectorA == vectorB);
        }
    }
    SUBCASE("operator!=")
    {
        {
            vec<5> vector5(1, 2, 3, 4, 5);
            vec<5> vec5Copy = vector5;
            CHECK_FALSE(vector5 != vec5Copy);
        }
        {
            vec<5> vectorA(1, 2, 3, 4, 5);
            vec<5> vectorB(6, 7, 8, 9, 10);
            CHECK(vectorA != vectorB);
        }
    }
    SUBCASE("operator+")
    {
        vec2 vectorA(1, 2);
        vec2 vectorB(3, 4);
        vec2 vectorC(4, 6);
        CHECK(vectorA + vectorB == vectorC);
    }
    SUBCASE("operator+=")
    {
        vec2 vectorA(1, 2);
        vec2 vectorB(3, 4);
        vec2 vectorC(4, 6);
        vectorA += vectorB;
        CHECK(vectorA == vectorC);
    }
    SUBCASE("operator-")
    {
        vec2 vectorA(1, 2);
        vec2 vectorB(3, 4);
        vec2 vectorC(-2, -2);
        CHECK(vectorA - vectorB == vectorC);
    }
    SUBCASE("operator-=")
    {
        vec2 vectorA(1, 2);
        vec2 vectorB(3, 4);
        vec2 vectorC(-2, -2);
        vectorA -= vectorB;
        CHECK(vectorA == vectorC);
    }
}
TEST_CASE("matrix: instantiation")
{
    SUBCASE("no argument")
    {
        mat2 matrix2;
        mat3 matrix3;
        mat4 matrix4;
        matrix<2, 3> matrix2X3;
    }
    SUBCASE("arguments")
    {
        {
            const size_t R = 2;
            const size_t C = 2;
            mat2 matrix2(1, 2, 3, 4);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix2[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 3;
            const size_t C = 3;
            mat3 matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix3[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 4;
            const size_t C = 4;
            mat4 matrix4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix4[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 2;
            const size_t C = 3;
            matrix<R, C> matrix2X3(1, 2, 3, 4, 5, 6);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix2X3[j][i] == (i * R + j) + 1);
            }
        }
    }
    SUBCASE("copy")
    {
        {
            const size_t R = 2;
            const size_t C = 2;
            mat2 matrix(1, 2, 3, 4);
            mat2 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 3;
            const size_t C = 3;
            mat3 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
            mat3 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 4;
            const size_t C = 4;
            mat4 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
            mat4 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 2;
            const size_t C = 3;
            matrix<R, C> matrix2X3(1, 2, 3, 4, 5, 6);
            matrix<R, C> matrixCopy(matrix2X3);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix2X3[j][i] == matrixCopy[j][i]);
            }
        }
    }
}
TEST_CASE("matrix: operators")
{
    SUBCASE("operator=")
    {
        const size_t R = 2;
        const size_t C = 2;
        mat2 matrix(1, 2, 3, 4);
        mat2 matrixCopy = matrix;
        for (size_t i = 0; i < C; i++)
        {
            for (size_t j = 0; j < R; j++)
            CHECK(matrix[j][i] == matrixCopy[j][i]);
        }
    }
    SUBCASE("operator[]")
    {
        mat2 matrix(1, 2, 3, 4);
        const size_t R = 2;
        const size_t C = 2;
        for (size_t i = 0; i < C; i++)
        {
            for (size_t j = 0; j < R; j++)
            CHECK(matrix[j][i] == (i * R + j) + 1);
        }
    }
    SUBCASE("operator==")
    {
        {
            mat2 matrixA(1, 2, 3, 4);
            mat2 matrixB = matrixA;
            CHECK(matrixA == matrixB);
        }
        {
            mat2 matrixA(1, 2, 3, 4);
            mat2 matrixB(5, 6, 7, 8);
            CHECK_FALSE(matrixA == matrixB);
        }
    }
    SUBCASE("operator!=")
    {
        {
            mat2 matrixA(1, 2, 3, 4);
            mat2 matrixB = matrixA;
            CHECK_FALSE(matrixA != matrixB);
        }
        {
            mat2 matrixA(1, 2, 3, 4);
            mat2 matrixB(5, 6, 7, 8);
            CHECK(matrixA != matrixB);
        }
    }
    SUBCASE("operator*")
    {
        mat2 matrixA(1, 2, 3, 4);
        mat2 matrixB(5, 6, 7, 8);
        mat2 matrixC(23, 34, 31, 46);

        CHECK(matrixC == matrixA * matrixB);
    }
}