#pragma once

#include <iostream>
#include <vector>

class Point3D {
public:
    Point3D(double x = 0, double y = 0, double z = 0);

    std::vector<double> getCoordinates() const { return {x_, y_, z_}; }
    double getX() const { return x_; }
    double getY() const { return y_; }
    double getZ() const { return z_; }

    double distance(const Point3D& p) const;
private:
    double x_, y_, z_;
};

std::ostream& operator<<(std::ostream& s, const Point3D& p);