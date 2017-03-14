#include "Cylinder.h"

Cylinder::Cylinder(Vec3 center, Vec3 axis, double radius, double height, Vec3 surfaceColor, double transparency, double refInd)
	: Shape(surfaceColor, transparency, refInd), center(center), axis(axis), radius(radius), height(height){
}

Vec3 *Cylinder::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	Vec3 rayDir2D = Vec3(rayDirection.X(), rayDirection.Y(), center.Z());
	Vec3 rayOri2D = Vec3(rayOrigin.X(), rayOrigin.Y(), center.Z());

	Vec3 proj = Vec3::proj(center - rayOri2D, rayDir2D) + rayOri2D;

	Vec3 ref = center - rayOri2D;

	if(Vec3::dot(ref, rayDir2D) < 0) {
		return nullptr;
	}

	double perp = (center - proj).length();

	if (perp < radius) {
		double d = sqrt(radius * radius - perp * perp);
		return new Vec3(proj - rayDirection.normalize() * d);
	} else {
		return nullptr;
	}
}

Vec3 Cylinder::getNormal(const Vec3 &hitpoint){
  return Vec3(0,0,0);
}

double Cylinder::angle(const Vec3 &point, const Vec3 &rayDirection) {
	return 0;
}

