
#include "Cylinder.h"
#include "Sphere.h"
#include "Scene.h"
#include "ImageWriter.h"

#include <iostream>
using namespace std;

int main () {
	Camera c(Vec3(0,0,0), Vec3(0,0,1), 40, 40, 0, 4000, 4000);
	Scene s(c);

	Sphere sph1 = Sphere(Vec3(0, 10, 100), 10, Vec3(20, 102, 20), 0.3);
	Sphere sph2 = Sphere(Vec3(-30, 20, 80), 7, Vec3(100, 40, 20), 0.3);
	Sphere sph3 = Sphere(Vec3(20, 0, 40), 13, Vec3(12, 32, 123), 0.3);

	s.AddShape(&sph1);
	s.AddShape(&sph2);
	s.AddShape(&sph3);
	Light l(Vec3(0, -50, 50), Vec3(0, 0, 10));
	s.AddLight(&l);

	// cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3 (0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;

	ImageWriter::write(s.Render());
}
