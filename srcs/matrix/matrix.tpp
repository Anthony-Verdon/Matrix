#include "matrix/matrix.hpp"

template<size_t R, size_t C>
matrix<R, C>::matrix()
{
}

template<size_t R, size_t C>
template<typename... Args>
matrix<R, C>::matrix(Args... args)
{
    static_assert(sizeof...(args) == R * C, "Incorrect number of arguments for matrix size.");
    
    float values[] = { static_cast<float>(args)... };
    for (size_t i = 0; i < C; i++)
    {
        for (size_t j = 0; j < R; j++)
            data[j][i] = values[i * R + j];
    }
}

template<size_t R, size_t C>
matrix<R, C>::matrix(const matrix<R, C> &instance)
{
    *this = instance;
}

template<size_t R, size_t C>
matrix<R, C> &matrix<R, C>::operator=(const matrix<R, C> &instance)
{
    if (this != &instance)
    {
        for (size_t i = 0; i < C; i++)
        {
            for (size_t j = 0; j < R; j++)
                data[j][i] = instance.data[j][i];
        }
    }

    return (*this);
}

template<size_t R, size_t C>
matrix<R, C>::~matrix()
{
}

template<size_t R, size_t C>
vec<C> &matrix<R, C>::operator[](size_t index)
{
    if (index >= R)
        throw(std::runtime_error("error: try to access a matrix of width " + std::to_string(R) + " at index " + std::to_string(index)));
    
    return (data[index]);
}

template<size_t R, size_t C>
const vec<C> &matrix<R, C>::operator[](size_t index) const
{
    if (index >= R)
        throw(std::runtime_error("error: try to access a matrix of width " + std::to_string(R) + " at index " + std::to_string(index)));

    return (data[index]);
}

template<size_t R, size_t C>
bool matrix<R, C>::operator==(const matrix<R, C> &instance) const
{
    for (size_t i = 0; i < C; i++)
    {
        for (size_t j = 0; j < R; j++)
        {
            if (data[j][i] != instance[j][i])
                return (false);
        }
    }

    return (true);
}

template<size_t R, size_t C>
bool matrix<R, C>::operator!=(const matrix<R, C> &instance) const
{
    return (!(*this == instance));
}

template<size_t R, size_t C>
template<size_t R2, size_t C2>
matrix<R, C2> matrix<R, C>::operator*(const matrix<R2, C2> &instance) const
{
    matrix<R, C2> result;

    if (C != R2)
        throw(std::runtime_error("matrix multiplication: number of column of first matrix should be equal to number of row of second matrix"));

    for (size_t j = 0; j < R; j++)
    {
        for (size_t i = 0; i < C2; i++)
        {
            result[j][i] = 0;
            for (size_t k = 0; k < R2; k++)
                result[j][i] += data[j][k] * instance[k][i];
        }
    }

    return (result);
}

template<size_t R, size_t C>
void matrix<R, C>::print() const
{
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}