#pragma once

#include "vec/vec.hpp"

template<size_t R, size_t C>
struct matrix
{
    public:
        matrix();
        template<typename... Args>
        matrix(Args... args);
        matrix(const matrix &instance);
        matrix &operator=(const matrix &instance);
        ~matrix();

        vec<C> &operator[](size_t index);
        const vec<C> &operator[](size_t index) const;

        bool operator==(const matrix &instance) const;
        bool operator!=(const matrix &instance) const;
        template<size_t R2, size_t C2>
        matrix<R, C2> operator*(const matrix<R2, C2> &instance) const;

        void print() const;
    protected:
        vec<C> data[R];
};

typedef matrix<2, 2> mat2;
typedef matrix<3, 3> mat3;
typedef matrix<4, 4> mat4;

#include "matrix/matrix.tpp"
