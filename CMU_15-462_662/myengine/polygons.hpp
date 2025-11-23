#pragma once

#include <iostream>
#include <vector>

#include "point3d.hpp"

class Triangle {
  public:
    Triangle(const Point3D &p1, const Point3D &p2, const Point3D &p3);

    std::vector<Point3D> getPoints() const { return {p1_, p2_, p3_}; }
    Point3D getP1() const { return p1_; }
    Point3D getP2() const { return p2_; }
    Point3D getP3() const { return p3_; }

  private:
    Point3D p1_, p2_, p3_;
};

std::ostream &operator<<(std::ostream &s, const Triangle &t);