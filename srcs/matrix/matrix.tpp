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
void matrix<R, C>::print() const
{
    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
            std::cout << data[i][j] << " ";
        std::cout << std::endl;
    }
}