#include "vec/vec.hpp"

int main()
{
    vec3 vecA(1, 2, 3);
    vec3 vecB(1, 2, 3);
    vec3 vecC(1, 2, 4);

    std::cout << (vecA == vecB) << std::endl;
    std::cout << (vecA != vecB) << std::endl;
    std::cout << (vecA == vecC) << std::endl;
    std::cout << (vecA != vecC) << std::endl;

    return (0);
}