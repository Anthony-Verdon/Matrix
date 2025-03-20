# Matrix

this project contains differents functions and structs useful for math, 2D and 3D rendering. Here is a list:

## structs
### vector
- vec\<L> struct, containing L float
- vec2, vec3, vec4 structs inheriting from vec but adding operator xyzw depending of the size
### matrix
- mat<R, C> struct, containing R * C float in a column major order
- mat2, mat3, mat4 structs, being typedef of mat struct

## functions
Here is `geometry.hpp`. I will probably add more functions, for 2D rendering for example, in the future.

    // vector
    template<size_t L>
    vec<L> normalize(const vec<L> &vector);
    vec3 crossProduct(const vec3 &vectorA, const vec3 &vectorB);
    template<size_t L>
    float dotProduct(const vec<L> &vectorA, const vec<L> &vectorB);
    
    // matrix
    mat4 translate(const vec3 &vector);
    mat4 scale(const vec3 &vector);
    mat4 rotate(float angle, const vec3 &axis);
    mat4 rotate(const vec4 &quat);

    // 3D
    mat4 perspective(float fov, float aspect, float near, float far);
    mat4 lookAt(const vec3 &position, const vec3 &target, const vec3 &initialUpVector);

## future
this project will probably be updated in the future. Here is a list of things I want to add:
- 2D functions, like ortho matrix
- more tests to check the validity of my lib
- rework the architecture to have `ml` in include path
- update of matrix functions to have a matrix parameter, like glm

the goal of this project is not to be the best math library, but one working fine and easy to understand (maybe I should add commentarys for that, and a better doc)