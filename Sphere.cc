#include "Sphere.h"

Sphere::Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency)
	: Shape(surfaceColor, transparency), center(center), radius(radius) {
}

bool Sphere::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	//double perp = center - (proj(center - rayOrigin, rayDirection) + rayOrigin);
}