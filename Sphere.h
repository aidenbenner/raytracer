#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
Vec3 center;
double radius;
public:
Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency, double refInd);
Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
double angle(const Vec3 &point, const Vec3 &rayDirection);

Vec3 getNormal(Vec3 hitpoint); 


};

#endif
