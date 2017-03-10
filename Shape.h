#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"

class Shape {
Vec3 surfaceColor;
double transparency;

public:

<<<<<<< HEAD
Shape(Vec3 surfaceColor, double transparency);
virtual double intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
=======
	Shape(Vec3 surfaceColor, double transparency);
	virtual bool intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
>>>>>>> 29e8670d33bb1b68fc6dcd5554ead5f53cccb35f

};

#endif
