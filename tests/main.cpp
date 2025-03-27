#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Matrix/Matrix.hpp"

TEST_CASE("vector: instantiation")
{
    SUBCASE("no argument")
    {
        ml::vec2 vector2;
        ml::vec3 vector3;
        ml::vec4 vector4;
        ml::vec<5> vector5;
    }
    SUBCASE("arguments")
    {
        ml::vec2 vector2(1, 2);
        for (int i = 0; i < 2; i++)
            CHECK(vector2[i] == (i + 1));
        ml::vec3 vector3(1, 2, 3);
        for (int i = 0; i < 3; i++)
            CHECK(vector3[i] == (i + 1));
        ml::vec4 vector4(1, 2, 3, 4);
        for (int i = 0; i < 4; i++)
            CHECK(vector4[i] == (i + 1));
        ml::vec<5> vector5(1, 2, 3, 4, 5);
        for (int i = 0; i < 5; i++)
            CHECK(vector5[i] == (i + 1));
    }
    SUBCASE("copy")
    {
        {
            ml::vec<2> vector2(1, 2);
            ml::vec2 vec2Copy(vector2);
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            ml::vec2 vector2(1, 2);
            ml::vec2 vec2Copy(vector2);
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            ml::vec<3> vector3(1, 2, 3);
            ml::vec3 vec3Copy(vector3);
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            ml::vec3 vector3(1, 2, 3);
            ml::vec3 vec3Copy(vector3);
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            ml::vec<4> vector4(1, 2, 3, 4);
            ml::vec4 vec4Copy(vector4);
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            ml::vec4 vector4(1, 2, 3, 4);
            ml::vec4 vec4Copy(vector4);
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            ml::vec<5> vector5(1, 2, 3, 4, 5);
            ml::vec<5> vec5Copy(vector5);
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
            ml::vec<2> vector2(1, 2);
            ml::vec2 vec2Copy = vector2;
            for (int i = 0; i < 2; i++)
                CHECK(vec2Copy[i] == (i + 1));
        }
        {
            ml::vec<3> vector3(1, 2, 3);
            ml::vec3 vec3Copy = vector3;
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            ml::vec3 vector3(1, 2, 3);
            ml::vec3 vec3Copy;
            vec3Copy = vector3;
            for (int i = 0; i < 3; i++)
                CHECK(vec3Copy[i] == (i + 1));
        }
        {
            ml::vec<4> vector4(1, 2, 3, 4);
            ml::vec4 vec4Copy = vector4;
            for (int i = 0; i < 4; i++)
                CHECK(vec4Copy[i] == (i + 1));
        }
        {
            ml::vec<5> vector5(1, 2, 3, 4, 5);
            ml::vec<5> vec5Copy = vector5;
            for (int i = 0; i < 5; i++)
                CHECK(vec5Copy[i] == (i + 1));
        }
    }
    SUBCASE("operator[]")
    {
        ml::vec<5> vector5(1, 2, 3, 4, 5);
        for (int i = 0; i < 5; i++)
            CHECK(vector5[i] == (i + 1));
    }
    SUBCASE("operator==")
    {
        {
            ml::vec<5> vector5(1, 2, 3, 4, 5);
            ml::vec<5> vec5Copy = vector5;
            CHECK(vector5 == vec5Copy);
        }
        {
            ml::vec<5> vectorA(1, 2, 3, 4, 5);
            ml::vec<5> vectorB(6, 7, 8, 9, 10);
            CHECK_FALSE(vectorA == vectorB);
        }
    }
    SUBCASE("operator!=")
    {
        {
            ml::vec<5> vector5(1, 2, 3, 4, 5);
            ml::vec<5> vec5Copy = vector5;
            CHECK_FALSE(vector5 != vec5Copy);
        }
        {
            ml::vec<5> vectorA(1, 2, 3, 4, 5);
            ml::vec<5> vectorB(6, 7, 8, 9, 10);
            CHECK(vectorA != vectorB);
        }
    }
    SUBCASE("operator+")
    {
        ml::vec2 vectorA(1, 2);
        ml::vec2 vectorB(3, 4);
        ml::vec2 vectorC(4, 6);
        CHECK(vectorA + vectorB == vectorC);
    }
    SUBCASE("operator+=")
    {
        ml::vec2 vectorA(1, 2);
        ml::vec2 vectorB(3, 4);
        ml::vec2 vectorC(4, 6);
        vectorA += vectorB;
        CHECK(vectorA == vectorC);
    }
    SUBCASE("operator- (substraction)")
    {
        ml::vec2 vectorA(1, 2);
        ml::vec2 vectorB(3, 4);
        ml::vec2 vectorC(-2, -2);
        CHECK(vectorA - vectorB == vectorC);
    }
    SUBCASE("operator- (reverse)")
    {
        {
            const ml::vec4 vectorA(1, 2, 3, 4);
            ml::vec4 vectorC = vectorA;
            ml::vec4 vectorB(-1, -2, -3, -4);
            
            vectorC = -vectorC;
            CHECK(vectorB == vectorC);
        }
        {
            ml::vec4 vectorC(1, 2, 3, 4);
            ml::vec4 vectorB(-1, -2, -3, -4);
        
            vectorC = -vectorC;
            CHECK(vectorB == vectorC);
        }
    }
    SUBCASE("operator-=")
    {
        ml::vec2 vectorA(1, 2);
        ml::vec2 vectorB(3, 4);
        ml::vec2 vectorC(-2, -2);
        vectorA -= vectorB;
        CHECK(vectorA == vectorC);
    }
}
TEST_CASE("matrix: instantiation")
{
    SUBCASE("no argument")
    {
        ml::mat2 matrix2;
        ml::mat3 matrix3;
        ml::mat4 matrix4;
        ml::mat<2, 3> matrix2X3;
    }
    SUBCASE("arguments")
    {
        {
            const size_t R = 2;
            const size_t C = 2;
            ml::mat2 matrix2(1, 2, 3, 4);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix2[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 3;
            const size_t C = 3;
            ml::mat3 matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix3[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 4;
            const size_t C = 4;
            ml::mat4 matrix4(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix4[j][i] == (i * R + j) + 1);
            }
        }
        {
            const size_t R = 2;
            const size_t C = 3;
            ml::mat<R, C> matrix2X3(1, 2, 3, 4, 5, 6);
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
            ml::mat2 matrix(1, 2, 3, 4);
            ml::mat2 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 3;
            const size_t C = 3;
            ml::mat3 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9);
            ml::mat3 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 4;
            const size_t C = 4;
            ml::mat4 matrix(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
            ml::mat4 matrixCopy(matrix);
            for (size_t i = 0; i < C; i++)
            {
                for (size_t j = 0; j < R; j++)
                CHECK(matrix[j][i] == matrixCopy[j][i]);
            }
        }
        {
            const size_t R = 2;
            const size_t C = 3;
            ml::mat<R, C> matrix2X3(1, 2, 3, 4, 5, 6);
            ml::mat<R, C> matrixCopy(matrix2X3);
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
        ml::mat2 matrix(1, 2, 3, 4);
        ml::mat2 matrixCopy = matrix;
        for (size_t i = 0; i < C; i++)
        {
            for (size_t j = 0; j < R; j++)
            CHECK(matrix[j][i] == matrixCopy[j][i]);
        }
    }
    SUBCASE("operator[]")
    {
        ml::mat2 matrix(1, 2, 3, 4);
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
            ml::mat2 matrixA(1, 2, 3, 4);
            ml::mat2 matrixB = matrixA;
            CHECK(matrixA == matrixB);
        }
        {
            ml::mat2 matrixA(1, 2, 3, 4);
            ml::mat2 matrixB(5, 6, 7, 8);
            CHECK_FALSE(matrixA == matrixB);
        }
    }
    SUBCASE("operator!=")
    {
        {
            ml::mat2 matrixA(1, 2, 3, 4);
            ml::mat2 matrixB = matrixA;
            CHECK_FALSE(matrixA != matrixB);
        }
        {
            ml::mat2 matrixA(1, 2, 3, 4);
            ml::mat2 matrixB(5, 6, 7, 8);
            CHECK(matrixA != matrixB);
        }
    }
    SUBCASE("operator+")
    {
        ml::mat2 matrixA(1, 2, 3, 4);
        ml::mat2 matrixB(5, 6, 7, 8);
        ml::mat2 matrixC(6, 8, 10, 12);

        CHECK(matrixC == matrixA + matrixB);
    }
    SUBCASE("operator+=")
    {
        ml::mat2 matrixA(1, 2, 3, 4);
        ml::mat2 matrixB(5, 6, 7, 8);
        ml::mat2 matrixC(6, 8, 10, 12);

        matrixA += matrixB;
        CHECK(matrixC == matrixA);
    }
    SUBCASE("operator-")
    {
        ml::mat2 matrixA(1, 2, 3, 4);
        ml::mat2 matrixB(5, 6, 7, 8);
        ml::mat2 matrixC(-4, -4, -4, -4);

        CHECK(matrixC == matrixA - matrixB);
    }
    SUBCASE("operator-=")
    {
        ml::mat2 matrixA(1, 2, 3, 4);
        ml::mat2 matrixB(5, 6, 7, 8);
        ml::mat2 matrixC(-4, -4, -4, -4);

        matrixA -= matrixB;
        CHECK(matrixC == matrixA);
    }
    SUBCASE("operator*")
    {
        ml::mat2 matrixA(1, 2, 3, 4);
        ml::mat2 matrixB(5, 6, 7, 8);
        ml::mat2 matrixC(23, 34, 31, 46);

        CHECK(matrixC == matrixA * matrixB);
    }
}
TEST_CASE("matrix: speciales matrices")
{
    SUBCASE("uniform")
    {
        {
            ml::mat2 matrixA;
            matrixA.uniform(0);
            ml::mat2 matrixB(0, 0, 0, 0);

            CHECK(matrixA == matrixB);
        }
        {
            ml::mat2 matrixA;
            matrixA.uniform(5);
            ml::mat2 matrixB(5, 5, 5, 5);

            CHECK(matrixA == matrixB);
        }
    }
    SUBCASE("identity")
    {
        {
            ml::mat2 matrixA;
            matrixA.identity();
            ml::mat2 matrixB(1, 0, 0, 1);

            CHECK(matrixA == matrixB);
        }
        {
            ml::mat3 matrixA;
            matrixA.identity();
            ml::mat3 matrixB(1, 0, 0, 0, 1, 0, 0, 0, 1);

            CHECK(matrixA == matrixB);
        }
        {
            ml::mat4 matrixA;
            matrixA.identity();
            ml::mat4 matrixB(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

            CHECK(matrixA == matrixB);
        }
    }
}
TEST_CASE("geometry")
{
    SUBCASE("normalization of a vector")
    {
        ml::vec3 vectorA(3, 0, 0);
        ml::vec3 vectorB(1, 0, 0);

        CHECK(ml::normalize(vectorA) == vectorB);
    }
    SUBCASE("cross product of a vector")
    {
        ml::vec3 vectorA(1, 2, 3);
        ml::vec3 vectorB(3, 4, 5);
        ml::vec3 vectorC(-2, 4, -2);

        CHECK(ml::crossProduct(vectorA, vectorB) == vectorC);
    }
    SUBCASE("dot product of a vector")
    {
        ml::vec3 vectorA(1, 2, 3);
        ml::vec3 vectorB(3, 4, 5);

        CHECK(ml::dotProduct(vectorA, vectorB) == 26);
    }
    SUBCASE("translate")
    {
        ml::vec3 vector(1, 2, 3);
        ml::mat4 matrix(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 2, 3, 1);
        ml::mat4 matrixIdentity;
        matrixIdentity.identity();
        CHECK(ml::translate(matrixIdentity, vector) == matrix); //@todo: check with OpenGL project if it's good
    }
    SUBCASE("scale")
    {
        ml::vec3 vector(1, 2, 3);
        ml::mat4 matrix(1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 0, 1);
        ml::mat4 matrixIdentity;
        matrixIdentity.identity();
        CHECK(ml::scale(matrixIdentity, vector) == matrix); //@todo: check with OpenGL project if it's good
    }
    SUBCASE("rotate")
    {
        ml::vec3 vector(1, 2, 3);
        ml::mat4 matrixIdentity;
        matrixIdentity.identity();
        ml::rotate(matrixIdentity, 90, vector); //@todo: check with OpenGL project if it's good
    }
}