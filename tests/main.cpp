#include "vec/vec.hpp"

int main()
{
    vec<5> vec(0, 1, 2, 3, 4);

    vec.print();

    vec2 vector(6, 7);
    vector.print();

    vec4 vector4;
    vector4.x = 1;
    vector4.y = 2;
    vector4.z = 3;
    vector4.w = 4;
    vector4.print();

    vec2 copy(vector);
    copy.print();

    vec4 vec4copy = vector4;
    vec4copy.print();

    return (0);
}