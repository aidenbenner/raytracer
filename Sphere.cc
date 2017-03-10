#include "Sphere.h"

Sphere::Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency)
	: Shape(surfaceColor, transparency) {
	this->center = center;
	this->radius = radius;
}