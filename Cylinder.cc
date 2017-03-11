#include "Cylinder.h"

Cylinder::Cylinder(Vec3 center, Vec3 axis, double radius, double height, Vec3 surfaceColor, double transparency, double refInd)
	: Shape(surfaceColor, transparency, refInd), center(center), axis(axis), radius(radius), height(height){
}

Vec3 *Cylinder::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	
}
