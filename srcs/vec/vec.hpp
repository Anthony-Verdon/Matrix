#pragma once

#include <cstdlib>

namespace ml
{
    template<size_t L>
    struct vec
    {
        public:
            vec();
            template<typename... Args>
            vec(Args... args);
            vec(const vec &instance);
            vec &operator=(const vec &instance);
            ~vec();

            float &operator[](size_t index);
            const float &operator[](size_t index) const;

            bool operator==(const vec &instance) const;
            bool operator!=(const vec &instance) const;
            vec operator+(const vec &instance) const;
            vec &operator+=(const vec &instance);
            vec operator-(const vec &instance) const;
            vec &operator-=(const vec &instance);

            void print() const;

        protected:
            float data[L];
    };

    struct vec2: public vec<2>
    {
        public:
            float &x = data[0];
            float &y = data[1];

            vec2();
            vec2(const vec<2> &instance);
            vec2(float x, float y);
            ~vec2();
    };

    struct vec3: public vec<3>
    {
        public:
            float &x = data[0];
            float &y = data[1];
            float &z = data[2];

            vec3();
            vec3(const vec<3> &instance);
            vec3(float x, float y, float z);
            ~vec3();
    };

    struct vec4: public vec<4>
    {
        public:
            float &x = data[0];
            float &y = data[1];
            float &z = data[2];
            float &w = data[3];

            vec4();
            vec4(const vec<4> &instance);
            vec4(float x, float y, float z, float w);
            ~vec4();
    };
}
#include "vec/vec.tpp"