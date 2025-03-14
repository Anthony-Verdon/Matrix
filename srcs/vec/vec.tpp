#include "vec/vec.hpp"
#include <iostream>

template<size_t L>
vec<L>::vec()
{
}

template<size_t L>
template<typename... Args>
vec<L>::vec(Args... args)
{
    static_assert(sizeof...(args) == L, "Incorrect number of arguments for vector size.");
    
    float values[] = { static_cast<float>(args)... };
    for (size_t i = 0; i < L; i++) {
        data[i] = values[i];
    }
}

template<size_t L>
vec<L>::~vec()
{

}

template<size_t L>
void vec<L>::print() const
{
    for (size_t i = 0; i < L; i++)
        std::cout << i << ": " << data[i] << std::endl;
}

vec2::vec2(): vec<2>()
{
}

vec2::vec2(float x, float y): vec<2>(x, y)
{
}

vec2::~vec2()
{
}

vec3::vec3(): vec<3>()
{
}

vec3::vec3(float x, float y, float z): vec<3>(x, y, z)
{
}

vec3::~vec3()
{
}

vec4::vec4(): vec<4>()
{
}

vec4::vec4(float x, float y, float z, float w): vec<4>(x, y, z, w)
{
}

vec4::~vec4()
{
}