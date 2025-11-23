#pragma once

#include <iostream>
#include <vector>

#include "point3d.hpp"

class Vector3D {
public:
    Vector3D(double x = 0, double y = 0, double z = 0);
    // Construct a Vector3D object from the coordinates of 'p'
    Vector3D(const Point3D& p);
    // Construct a Vector3D object from the difference between the coordinates of 'p1' and 'p2' (p2-p1)
    Vector3D(const Point3D& p1, const Point3D& p2);

    std::vector<double> getComponents() const { return {x_, y_, z_}; } 
    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

    // Check if this Vector3D object is a null vector
    bool isNull() const;

    // Calculate the magnitude of this Vector3D object
    double magnitude() const;
    // Calculate the norm (aka magnitude) of this Vector3D object
    double norm() const;

    // Calculate the unit vector of this Vector3D object
    Vector3D unit() const;

    // Check whether this Vector3D object is parallel to 'v'
    bool isCodirectionalWith(const Vector3D& v) const;

    // Calculate the dot product between this Vector3D object and 'v'
    double dotProduct(const Vector3D& v) const;

    // Calculate the cross product between this Vector3D object and 'v'
    Vector3D crossProduct(const Vector3D& v) const;
    // Calculate the vector product (aka cross product) between this Vector3D object and 'v'
    Vector3D vectorProduct(const Vector3D& v) const ;
private:
    double x_, y_, z_;
};

std::ostream& operator<<(std::ostream& s, const Vector3D& v);
bool operator==(const Vector3D& v1, const Vector3D& v2);