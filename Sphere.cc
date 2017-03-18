#include "Sphere.h"

Sphere::Sphere(Vec3 center, double radius, Vec3 surfaceColor, double transparency, double refracInd)
	: Shape(surfaceColor, transparency, refracInd), center(center), radius(radius) {
}

Vec3 *Sphere::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	Vec3 proj = Vec3::proj(center - rayOrigin, rayDirection) + rayOrigin;

	Vec3 ref = center - rayOrigin;

	if(Vec3::dot(ref, rayDirection) < 0) {
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

Vec3 * Sphere::selfIntersection(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	Vec3 proj = Vec3::proj(center - rayOrigin, rayDirection) + rayOrigin;

	Vec3 ref = center - rayOrigin;

	if(Vec3::dot(ref, rayDirection) < 0) {
		return nullptr;
	}

	double perp = (center - proj).length();
	if (perp < radius) {
		double d = sqrt(radius * radius - perp * perp);
		return new Vec3(proj + rayDirection.normalize() * d);
	} else {
		return nullptr;
	}
}


Vec3 Sphere::getNormal(const Vec3& hitpoint) {
	return hitpoint - center;
}

double Sphere::angle(const Vec3 &point, const Vec3 &rayDirection) {
	Vec3 normal = center - point;
	return acos(Vec3::dot(normal, rayDirection)/ (rayDirection.length() * normal.length()));
}
