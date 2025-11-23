#include "point3d.hpp"

#include <cmath>
#include <iostream>

// Begin Point3D methods

Point3D::Point3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

double Point3D::distance(const Point3D &p) const {
    return std::sqrt(this->x_ * p.x_ + this->y_ * p.y_ + this->z_ * p.z_);
}

// End Point3D methods

// Begin operator overloads

std::ostream &operator<<(std::ostream &s, const Point3D &p) {
    s << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
    return s;
}

// End operator overloads