#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
  public:
    Plane(Vec3 normal, Vec3 point, Vec3 surfaceColor, double transparency, double refInd);
    Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
    double angle(const Vec3 &point, const Vec3 &rayDirection);
    Vec3 getNormal(Vec3 hitpoint) ;

  private:
    Vec3 normal;
    Vec3 point;
};
#endif
