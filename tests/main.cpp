#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "vec/vec.hpp"

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