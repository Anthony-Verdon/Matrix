#include "vec/vec.hpp"

int main()
{
    vec3 vecA(1, 2, 3);
    vec3 vecB(4, 5, 6);

    vec3 vecC = vecA + vecB;
    vecC.print();
    vecC += vecA;
    vecC.print();

    vecC -= vecA;
    vecC.print();
    vec3 vecD = vecC - vecB;
    vecD.print();

    return (0);
}