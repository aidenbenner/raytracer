#include "Matrix.h"
#include "Vec3.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Scene.h"

#include <iostream>
using namespace std;

int main () {
  Scene s();

  Sphere sph = Sphere(Vec3(0, 0, 2), 1, Vec3(20, 102, 20), 0.3);
  cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;
}
