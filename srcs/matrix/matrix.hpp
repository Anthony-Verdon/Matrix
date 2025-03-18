#pragma once

#include "vec/vec.hpp"

template<size_t R, size_t C>
struct matrix
{
    public:
        matrix();
        template<typename... Args>
        matrix(Args... args);
        ~matrix();

        void print() const;
    protected:
        vec<C> data[R];
};

typedef matrix<2, 2> mat2;
typedef matrix<3, 3> mat3;
typedef matrix<4, 4> mat4;

#include "matrix/matrix.tpp"
