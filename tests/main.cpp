#include "vec/vec.hpp"

int main()
{
    vec2 vector;
    vector.data[0] = 1;
    vector.data[1] = 2;
    vector.print();
    std::cout << vector.x << " " << vector.y << std::endl;
    vector.x = 3;
    vector.y = 4;
    vector.print();
    std::cout << vector.x << " " << vector.y << std::endl;
    return (0);
}