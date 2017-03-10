#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.h"

class Sphere : public Shape {
	Vec3 center;
	double radius;	
public:
	Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency);
	
};

#endif
