#include "Sphere.h"

Sphere::Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency)
	: Shape(surfaceColor, transparency), center(center), radius(radius) {
}

Vec3 *Sphere::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	Vec3 proj = Vec3::proj(center - rayOrigin, rayDirection) + rayOrigin;
	double perp = (center - proj).length();

	if (perp <= radius) {
		double d = sqrt(radius * radius - perp * perp);
		return new Vec3(proj - rayDirection * d);
	} else return NULL;
}
