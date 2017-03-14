#include "Cylinder.h"

Cylinder::Cylinder(Vec3 center, Vec3 axis, double radius, double height, Vec3 surfaceColor, double transparency, double refInd)
	: Shape(surfaceColor, transparency, refInd), center(center), axis(axis), radius(radius), height(height){
}

Vec3 *Cylinder::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	
}

Vec3 Cylinder::getNormal(const Vec3 &hitpoint){
  return Vec3(0,0,0);
}

double Cylinder::angle(const Vec3 &point, const Vec3 &rayDirection) {
	Vec3 origin = Vec3(center.X(), point.Y(), center.Z());

	Vec3 normal = point - origin;

	return acos(Vec3::dot(normal, rayDirection)/ (rayDirection.length() * normal.length()));
}

