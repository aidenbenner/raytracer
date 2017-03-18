#include "Plane.h"
#include  <cassert>

Plane::Plane(Vec3 normal, Vec3 point, Vec3 surfaceColor, double refInd, double transparency)
	: Shape(surfaceColor, transparency, refInd), normal(normal), point(point) {
}

Vec3 *Plane::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	double lambda = (Vec3::dot(normal, point) - Vec3::dot(normal, rayOrigin)) / Vec3::dot(normal, rayDirection);

	if (lambda > EPS) {
		return new Vec3(rayOrigin + rayDirection * lambda);
	} else return NULL;
}


Vec3 Plane::getNormal(const Vec3 &hitpoint){
  return normal * (Vec3::dot(hitpoint, normal) > 0 ? -1 : 1);
}

Vec3 * Plane::selfIntersection(const Vec3 &rayOrigin, const Vec3 &rayDirection){
  //TODO
  cout << "plane " << endl;
  return nullptr;
}

double Plane::angle(const Vec3 &point, const Vec3 &rayDirection) {
	return acos(Vec3::dot(normal, rayDirection)/ (rayDirection.length() * normal.length()));
}

