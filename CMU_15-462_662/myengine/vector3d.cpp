#include "vector3d.hpp"

#include "cmath"
#include <cassert>
#include <iostream>

// Begin Vector3D methods

Vector3D::Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}

Vector3D::Vector3D(const Point3D &p) : Vector3D(p.getX(), p.getY(), p.getZ()) {}

Vector3D::Vector3D(const Point3D &p1, const Point3D &p2)
    : Vector3D(p2.getX() - p1.getX(), p2.getY() - p1.getY(), p2.getZ() - p1.getZ()) {}

bool Vector3D::isNull() const { return (x_ == 0 && y_ == x_ && z_ == x_); }

double Vector3D::magnitude() const { return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_); }

double Vector3D::norm() const { return this->magnitude(); }

Vector3D Vector3D::unit() const {
    if (this->isNull())
        return Vector3D();
    return (*this / this->magnitude());
}

bool Vector3D::isCodirectionalWith(const Vector3D &v) const {
    if (this->isNull() || v.isNull())
        return false;
    return this->unit() == v.unit();
}

double Vector3D::dotProduct(const Vector3D &v) const { return (this->x_ * v.x_ + this->y_ * v.y_ + this->z_ * v.z_); }

Vector3D Vector3D::crossProduct(const Vector3D &v) const {
    return Vector3D(this->y_ * v.z_ - this->z_ * v.y_, this->z_ * v.x_ - this->x_ * v.z_,
                    this->x_ * v.y_ - this->y_ * v.x_);
}

Vector3D Vector3D::vectorProduct(const Vector3D &v) const { return crossProduct(v); }

// End Vector3D methods

// Begin operator overloads

std::ostream &operator<<(std::ostream &s, const Vector3D &v) {
    s << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
    return s;
}

bool operator==(const Vector3D &v1, const Vector3D &v2) {
    return (v1.getX() == v2.getX() && v1.getY() == v2.getY() && v1.getZ() == v2.getZ());
}

Vector3D operator+(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
}

Vector3D operator-(const Vector3D &v1, const Vector3D &v2) {
    return Vector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

Vector3D operator*(const double k, const Vector3D &v) { return Vector3D(k * v.getX(), k * v.getY(), k * v.getZ()); }

Vector3D operator/(const Vector3D &v, const double k) {
    assert(k);
    return Vector3D(v.getX() / k, v.getY() / k, v.getZ() / k);
}

// End operator overloads