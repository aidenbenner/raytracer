#include "Matrix.h"
#include "Vec3.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Scene.h"
#include "ImageWriter.h"

#include <iostream>
using namespace std;


int main () {
  	Camera c(Vec3(0,0,0), Vec3(1,0,0), 10, 10, 1, 1920, 1080); 
	Scene s(c);

	Sphere sph = Sphere(Vec3(0, 0, 2), 1, Vec3(20, 102, 20), 0.3);
	s.AddShape(&sph); 




	cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3 (0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;

	vector<vector<Vec3> > image;

	// generating random gradient
	for (int i = 0; i < 400; ++i) {
		vector<Vec3> temp;
		for (int j = 0; j < 400; ++j) {
			temp.push_back(Vec3(i ,i,i));
		}
		image.push_back(temp);
	}

	ImageWriter::write(image);
}
