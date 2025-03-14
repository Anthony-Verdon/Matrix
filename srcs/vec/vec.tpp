#include "vec/vec.hpp"
#include <iostream>

template<size_t L>
void vec<L>::print() const
{
    for (size_t i = 0; i < L; i++)
        std::cout << i << ": " << data[i] << std::endl;
}