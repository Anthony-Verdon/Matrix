#pragma once

#include "vec/vec.hpp"

namespace ml
{
    template<size_t R, size_t C>
    struct mat
    {
        public:
            mat();
            template<typename... Args>
            mat(Args... args);
            mat(const mat &instance);
            mat &operator=(const mat &instance);
            ~mat();

            vec<C> &operator[](size_t index);
            const vec<C> &operator[](size_t index) const;

            bool operator==(const mat &instance) const;
            bool operator!=(const mat &instance) const;
            mat operator+(const mat &instance) const;
            mat &operator+=(const mat &instance);
            mat operator-(const mat &instance) const;
            mat &operator-=(const mat &instance);
            template<size_t R2, size_t C2>
            mat<R, C2> operator*(const mat<R2, C2> &instance) const;

            void uniform(float value);
            void identity();
            
            float *ptr() { return (&data[0][0]); }
            const float *ptr() const { return (&data[0][0]); }

            void print() const;
        protected:
            vec<C> data[R];
    };

    typedef mat<2, 2> mat2;
    typedef mat<3, 3> mat3;
    typedef mat<4, 4> mat4;
}

#include "mat/mat.tpp"
