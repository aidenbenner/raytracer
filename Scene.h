#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include "Camera.h"
#include "Shape.h"
#include <vector>

using namespace std;

class Scene {
public:
Scene(Camera c) : cam(c) {
}

inline void AddShape(Shape* s) {
	shapes.push_back(s);
}

Vec3 Scene::Trace(Vec3& dir, Vec3& pos); 

void Render();

private:
Camera cam;
vector<Shape*> shapes;


};

#endif
