#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape.h"

class Cylinder : public Shape {
	Vec3 center, axis;
	double radius, height;	

public:
	Cylinder(Vec3 center, Vec3 axis, double radius, double height, Vec3 surfaceColor, double transparency, 
      double refInd);
	Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
	double angle(const Vec3 &point, const Vec3 &rayDirection);
	Vec3 getNormal(const Vec3 &hitpoint);
};

#endif
