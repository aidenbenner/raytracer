#include "Light.h"
Light::Light(Vec3 position, Vec3 color, double brightness) : color(color), position(position), brightness(brightness) {
}
Vec3 Light::getPos() {
	return position;
}

double Light::getIntensity(const Vec3 &pos) {
	double dist = (position - pos).length();
	cout << dist << endl;
	cout << brightness / (4 * PI * dist * dist);
	
	return brightness / (4 * PI * dist * dist);
}
