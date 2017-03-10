#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
Vec3 center;
double radius;
public:
Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency);
double intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
};

#endif
