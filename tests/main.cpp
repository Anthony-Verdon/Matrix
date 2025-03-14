#include "vec/vec.hpp"

int main()
{
    vec3 vecA(1, 2, 3);
    vec3 vecB(4, 5, 6);

    vec3 vecC = vecA + vecB;
    vecC.print();
    vecC += vecA;
    vecC.print();

    std::cout << vecC[0] << std::endl;
    std::cout << vecC[1] << std::endl;
    std::cout << vecC[2] << std::endl;

    try
    {
        std::cout << vecC[3] << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cout << exception.what() << std::endl;
    }

    return (0);
}