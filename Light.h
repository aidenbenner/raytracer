#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3.h"
using namespace std;

class Light {
Vec3 position;
Vec3 color;
double brightness;
public:
	Light(Vec3 position, Vec3 color, double brightness);
	Vec3 getPos();
	double getIntensity(const Vec3 & pos);
};

#endif
