#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"

class Shape {
	Vec3 surfaceColor;
	double transparency;
	Shape(Vec3 surfaceColor, double transparency);
};


#endif