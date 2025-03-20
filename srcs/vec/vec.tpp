#include "vec/vec.hpp"
#include <iostream>

namespace ml
{

    template<size_t L>
    inline vec<L>::vec()
    {
        static_assert(L != 0, "length shouldn't be equal to 0");
    }

    template<size_t L>
    template<typename... Args>
    inline vec<L>::vec(Args... args)
    {
        static_assert(L != 0, "length shouldn't be equal to 0");
        static_assert(sizeof...(args) == L, "Incorrect number of arguments for vector size.");
        
        float values[] = { static_cast<float>(args)... };
        for (size_t i = 0; i < L; i++)
            data[i] = values[i];
    }

    template<size_t L>
    inline vec<L>::vec(const vec<L> &instance)
    {
        *this = instance;
    }

    template<size_t L>
    inline vec<L> &vec<L>::operator=(const vec<L> &instance)
    {
        if (this != &instance)
        {
            for (size_t i = 0; i < L; i++) 
                data[i] = instance[i];
        }

        return (*this);
    }

    template<size_t L>
    inline vec<L>::~vec()
    {
    }

    template<size_t L>
    inline float &vec<L>::operator[](size_t index)
    {
        if (index >= L)
            throw(std::runtime_error("error: try to access a vector of size " + std::to_string(L) + " at index " + std::to_string(index)));
        
        return (data[index]);
    }

    template<size_t L>
    inline const float &vec<L>::operator[](size_t index) const
    {
        if (index >= L)
            throw(std::runtime_error("error: try to access a vector of size " + std::to_string(L) + " at index " + std::to_string(index)));

        return (data[index]);
    }

    template<size_t L>
    inline bool vec<L>::operator==(const vec<L> &instance) const
    {
        for (size_t i = 0; i < L; i++) 
        {
            if (data[i] != instance[i])
                return (false);
        }

        return (true);
    }

    template<size_t L>
    inline bool vec<L>::operator!=(const vec<L> &instance) const
    {
        return (!(*this == instance));
    }

    template<size_t L>
    inline vec<L> vec<L>::operator+(const vec<L> &instance) const
    {
        vec<L> result;
        for (size_t i = 0; i < L; i++) 
            result[i] = data[i] + instance[i];

        return (result);
    }

    template<size_t L>
    inline vec<L> &vec<L>::operator+=(const vec<L> &instance)
    {
        *this = *this + instance;
        return (*this);
    }

    template<size_t L>
    inline vec<L> vec<L>::operator-(const vec<L> &instance) const
    {
        vec<L> result;
        for (size_t i = 0; i < L; i++) 
            result[i] = data[i] - instance[i];

        return (result);
    }

    template<size_t L>
    inline vec<L> &vec<L>::operator-=(const vec<L> &instance)
    {
        *this = *this - instance;
        return (*this);
    }

    template<size_t L>
    inline vec<L> vec<L>::operator-() const
    {
        vec<L> result;
        for (size_t i = 0; i < L; i++) 
            result[i] = -data[i];

        return (result);
    }

    template<size_t L>
    inline vec<L> vec<L>::operator*(float scalar) const
    {
        vec<L> result;
        for (size_t i = 0; i < L; i++) 
            result[i] = data[i] * scalar;

        return (result);
    }

    template<size_t L>
    inline vec<L> &vec<L>::operator*=(float scalar)
    {
        *this = *this * scalar;
        return (*this);
    }

    template<size_t L>
    inline vec<L> operator*(float scalar, const vec<L> &vector)
    {
        return (vector * scalar);
    }

    template<size_t L>
    inline vec<L> vec<L>::operator*(const vec<L> &instance) const
    {
        vec<L> result;
        for (size_t i = 0; i < L; i++) 
            result[i] = data[i] * instance[i];

        return (result);
    }

    template<size_t L>
    inline vec<L> &vec<L>::operator*=(const vec<L> &instance)
    {
        *this = *this * instance;
        return (*this);
    }

    template<size_t L>
    inline void vec<L>::print() const
    {
        for (size_t i = 0; i < L; i++)
            std::cout << i << ": " << data[i] << std::endl;
    }

    inline vec2::vec2(): vec<2>()
    {
    }

    inline vec2::vec2(const vec<2> &instance): vec<2>(instance)
    {
    }

    inline vec2::vec2(float x, float y): vec<2>(x, y)
    {
    }

    inline vec2 &vec2::operator=(const vec2 &instance)
    {
        if (this != &instance)
        {
            for (size_t i = 0; i < 2; i++) 
                data[i] = instance[i];
        }

        return (*this);
    }

    inline vec2::~vec2()
    {
    }

    inline vec3::vec3(): vec<3>()
    {
    }

    inline vec3::vec3(const vec<3> &instance): vec<3>(instance)
    {
    }

    inline vec3::vec3(float x, float y, float z): vec<3>(x, y, z)
    {
    }

    inline vec3 &vec3::operator=(const vec3 &instance)
    {
        if (this != &instance)
        {
            for (size_t i = 0; i < 3; i++) 
                data[i] = instance[i];
        }

        return (*this);
    }

    inline vec3::~vec3()
    {
    }

    inline vec4::vec4(): vec<4>()
    {
    }

    inline vec4::vec4(const vec<4> &instance): vec<4>(instance)
    {
    }

    inline vec4::vec4(float x, float y, float z, float w): vec<4>(x, y, z, w)
    {
    }

    inline vec4 &vec4::operator=(const vec4 &instance)
    {
        if (this != &instance)
        {
            for (size_t i = 0; i < 4; i++) 
                data[i] = instance[i];
        }

        return (*this);
    }
    
    inline vec4::~vec4()
    {
    }
}