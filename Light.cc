#include "Light.h"
Light::Light(Vec3 position, Vec3 color) : color(color), position(position) {
}
Vec3 Light::getPos() {
	return position;
}
