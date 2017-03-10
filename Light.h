#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3.h"
using namespace std;

class Light {
	Vec3 position;
	Vec3 color;
public:
	Light(Vec3 position, Vec3 color);
};

#endif
