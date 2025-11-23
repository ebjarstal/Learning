#pragma once

#include "point3d.hpp"
#include "polygons.hpp"

namespace Rasterization {

bool pointInTriangle(const Point3D &p, const Triangle &t);

} // namespace Rasterization