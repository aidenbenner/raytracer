#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"
#include "Matrix.h"
#include "Constants.h"

class Shape {
	Vec3 surfaceColor;
	double transparency;


public:

	Shape(Vec3 surfaceColor, double transparency);
	virtual Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);

};

#endif
