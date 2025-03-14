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
    for (size_t i = 0; i < L; i++)
        data[i] = values[i];
}

template<size_t L>
vec<L>::vec(const vec<L> &instance)
{
    *this = instance;
}

template<size_t L>
vec<L> &vec<L>::operator=(const vec<L> &instance)
{
    if (this != &instance)
    {
        for (size_t i = 0; i < L; i++) 
            data[i] = instance.data[i];
    }

    return (*this);
}

template<size_t L>
vec<L>::~vec()
{

}

template<size_t L>
bool vec<L>::operator==(const vec<L> &instance) const
{
    for (size_t i = 0; i < L; i++) 
    {
        if (data[i] != instance.data[i])
            return (false);
    }

    return (true);
}

template<size_t L>
bool vec<L>::operator!=(const vec<L> &instance) const
{
    return (!(*this == instance));
}

template<size_t L>
vec<L> vec<L>::operator+(const vec<L> &instance) const
{
    vec<L> result;
    for (size_t i = 0; i < L; i++) 
        result.data[i] = data[i] + instance.data[i];

    return (result);
}

template<size_t L>
vec<L> &vec<L>::operator+=(const vec<L> &instance)
{
    for (size_t i = 0; i < L; i++) 
        data[i] += instance.data[i];

    return (*this);
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

vec2::vec2(const vec<2> &instance): vec<2>(instance)
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

vec3::vec3(const vec<3> &instance): vec<3>(instance)
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

vec4::vec4(const vec<4> &instance): vec<4>(instance)
{
}

vec4::vec4(float x, float y, float z, float w): vec<4>(x, y, z, w)
{
}

vec4::~vec4()
{
}