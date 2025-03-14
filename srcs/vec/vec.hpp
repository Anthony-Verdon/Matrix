#pragma once

#include <cstdlib>

template<size_t L>
struct vec
{
    public:
        void print() const;

    protected:
        float data[L];
};

struct vec2: public vec<2>
{
    public:
        float &x = data[0];
        float &y = data[1];
};

struct vec3: public vec<3>
{
    public:
        float &x = data[0];
        float &y = data[1];
        float &z = data[2];
};

struct vec4: public vec<4>
{
    public:
        float &x = data[0];
        float &y = data[1];
        float &z = data[2];
        float &w = data[3];
};

#include "vec/vec.tpp"