#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
Vec3 normal, point;
public:
	Plane(Vec3 normal, Vec3 point, Vec3 surfaceColor, double transparency);
	Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	double angle(const Vec3 &point, const Vec3 &rayDirection);
};

#endif
