#include <iostream>

#include "point3d.hpp"
#include "vector3d.hpp"
#include "polygons.hpp"
#include "rasterization.hpp"

int main(int, char* []) {
    auto p0 = Point3D(1.5, 0.5);
    auto p1 = Point3D(9.7, 2.4);
    auto p2 = Point3D(6.6, 9.25);
    auto t = Triangle(p0, p1, p2);
    auto q = Point3D(5.5, 4.5);

    std::cout << Rasterization::pointInTriangle(q, t) << std::endl;
    return 0;
}
