#include "rasterization.hpp"

#include "vector3d.hpp"

namespace Rasterization {

bool pointInTriangle(const Point3D& p, const Triangle& t) {
    // Vectors formed by the points of triangle 't'
    const auto v1 = Vector3D(t.getP1(), t.getP2());
    const auto v2 = Vector3D(t.getP2(), t.getP3());
    const auto v3 = Vector3D(t.getP3(), t.getP1());

    // Vectors formed by point 'p' and the points of triangle 't'
    const auto v4 = Vector3D(t.getP1(), p);
    const auto v5 = Vector3D(t.getP2(), p);
    const auto v6 = Vector3D(t.getP3(), p);

    // Cross product between each side of the triangle and the vectors formed with point 'p'
    const auto v1v4 = v1.crossProduct(v4);
    const auto v2v5 = v2.crossProduct(v5);
    const auto v3v6 = v3.crossProduct(v6);

    // If the vectors from the cross products are all codirectional with one another then 'p' is in 't'
    return (v1v4.isCodirectionalWith(v2v5) && v2v5.isCodirectionalWith(v3v6));
}

}