#include "mat/mat.hpp"

namespace ml
{
    template<size_t R, size_t C>
    mat<R, C>::mat()
    {
        static_assert(R != 0, "row number shouldn't be equal to 0");
        static_assert(C != 0, "column number shouldn't be equal to 0");
        uniform(0);
    }

    template<size_t R, size_t C>
    template<typename... Args>
    mat<R, C>::mat(Args... args)
    {
        static_assert(R != 0, "row number shouldn't be equal to 0");
        static_assert(C != 0, "column number shouldn't be equal to 0");
        static_assert(sizeof...(args) == R * C, "Incorrect number of arguments for mat size.");
        
        float values[] = { static_cast<float>(args)... };
        for (size_t i = 0; i < C; i++)
        {
            for (size_t j = 0; j < R; j++)
                data[j][i] = values[i * R + j];
        }
    }

    template<size_t R, size_t C>
    mat<R, C>::mat(const mat<R, C> &instance)
    {
        *this = instance;
    }

    template<size_t R, size_t C>
    mat<R, C> &mat<R, C>::operator=(const mat<R, C> &instance)
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
    mat<R, C>::~mat()
    {
    }

    template<size_t R, size_t C>
    vec<C> &mat<R, C>::operator[](size_t index)
    {
        if (index >= R)
            throw(std::runtime_error("error: try to access a mat of width " + std::to_string(R) + " at index " + std::to_string(index)));
        
        return (data[index]);
    }

    template<size_t R, size_t C>
    const vec<C> &mat<R, C>::operator[](size_t index) const
    {
        if (index >= R)
            throw(std::runtime_error("error: try to access a mat of width " + std::to_string(R) + " at index " + std::to_string(index)));

        return (data[index]);
    }

    template<size_t R, size_t C>
    bool mat<R, C>::operator==(const mat<R, C> &instance) const
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
    bool mat<R, C>::operator!=(const mat<R, C> &instance) const
    {
        return (!(*this == instance));
    }

    template<size_t R, size_t C>
    mat<R, C> mat<R, C>::operator+(const mat<R, C> &instance) const
    {
        mat<R, C> result;

        for (size_t j = 0; j < R; j++)
        {
            for (size_t i = 0; i < C; i++)
            {
                result[j][i] = data[j][i] + instance[j][i];
            }
        }

        return (result);
    }

    template<size_t R, size_t C>
    mat<R, C> &mat<R, C>::operator+=(const mat<R, C> &instance)
    {
        *this = *this + instance;
        return (*this);
    }

    template<size_t R, size_t C>
    mat<R, C> mat<R, C>::operator-(const mat<R, C> &instance) const
    {
        mat<R, C> result;

        for (size_t j = 0; j < R; j++)
        {
            for (size_t i = 0; i < C; i++)
            {
                result[j][i] = data[j][i] - instance[j][i];
            }
        }

        return (result);
    }

    template<size_t R, size_t C>
    mat<R, C> &mat<R, C>::operator-=(const mat<R, C> &instance)
    {
        *this = *this - instance;
        return (*this);
    }

    template<size_t R, size_t C>
    template<size_t R2, size_t C2>
    mat<R, C2> mat<R, C>::operator*(const mat<R2, C2> &instance) const
    {
        mat<R, C2> result;

        if (C != R2)
            throw(std::runtime_error("mat multiplication: number of column of first mat should be equal to number of row of second mat"));

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
    template<size_t R2, size_t C2>
    mat<R, C2> &mat<R, C>::operator*=(const mat<R2, C2> &instance)
    {
        *this = *this * instance;
        return (*this);
    }

    template<size_t R, size_t C>
    void mat<R, C>::uniform(float value)
    {
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
                data[j][i] = value;
        }
    }

    template<size_t R, size_t C>
    void mat<R, C>::identity()
    {
        static_assert(R == C, "for an identity matrix, row and column should be equal");
        uniform(0);
        for (size_t i = 0; i < R; i++)
            data[i][i] = 1;
    }

    template<size_t R, size_t C>
    void mat<R, C>::print() const
    {
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
                std::cout << data[i][j] << " ";
            std::cout << std::endl;
        }
    }
}