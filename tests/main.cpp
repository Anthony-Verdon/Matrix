#include "vec/vec.hpp"

int main()
{
    vec<5> vec(0, 1, 2, 3, 4);

    vec.print();

    vec2 vector(6, 7);
    vector.print();

    vec4 vector4;
    vector4.print();

    vec2 copy(vector);
    copy.print();
    return (0);
}