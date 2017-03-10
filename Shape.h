#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"

class Shape {
	Vec3 surfaceColor;
	double transparency;

public:

	Shape(Vec3 surfaceColor, double transparency);

};

#endif
