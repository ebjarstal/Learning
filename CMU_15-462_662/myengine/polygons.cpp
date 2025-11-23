#include "polygons.hpp"

#include <iostream>

#include "point3d.hpp"

// Begin Triangle methods

Triangle::Triangle(const Point3D& p1, const Point3D& p2, const Point3D& p3)
    : p1_(std::move(p1)), p2_(std::move(p2)), p3_(std::move(p3)) {}

// End Triangle methods

// Begin operator overloads

std::ostream& operator<<(std::ostream& s, const Triangle& t) {
    s << "(" << t.getP1() << ", " << t.getP2() << ", " << t.getP3() << ")";
    return s;
}

// End operator overloads