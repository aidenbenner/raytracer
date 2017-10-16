#include "Cylinder.h"
#include "Sphere.h"
#include "Plane.h"
#include "Scene.h"
#include "ImageWriter.h"
#include "Vec3.h"

#include <iostream>
using namespace std;

void sceneA () {
  Camera c(Vec3(0, 0.1 , 0), Vec3(PI / 12,0, 0), 90, 90, 0, 200, 200);
  Scene s(c);

  Sphere sph1 = Sphere(Vec3(0, -3, 20), 2, Vec3(20, 102, 20), 1, 0);
  Sphere sph2 = Sphere(Vec3(0, -3, 10), 2, Vec3(100, 40, 20), 1.3, 1);
  Sphere sph3 = Sphere(Vec3(4, -3, 20), 2, Vec3(12, 32, 123), 1, 0);
  Sphere sph4 = Sphere(Vec3(-4, -3, 20), 2, Vec3(130, 0, 0), 1, 0);

  Plane pla1 = Plane(Vec3(0, -3, 0), Vec3(0,-6, 100), Vec3(200, 170, 190), 0.4, 0);
  //	Plane pla2 = Plane(Vec3(0, 0, -1), Vec3(0, 0, 100), Vec3(46, 220, 32), 0.3, 0);

  s.AddShape(&sph1);
  s.AddShape(&sph3);
  s.AddShape(&sph4);
  s.AddShape(&pla1);

  Light l(Vec3(0, 3, 0), Vec3(255, 255, 255), 10000);
  Light l2(Vec3(0, 20, 23), Vec3(255, 255, 255), 10000);

  s.AddLight(&l2);

  // cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3 (0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;

  ImageWriter::write(s.Render());
}

void sceneB () {
  Camera c(Vec3(0, 10.1, -50.1), Vec3(PI / 12, 0, 0), 90, 90, 0, 1000, 1000);
  Scene s(c);

  Sphere sph1 = Sphere(Vec3(15, -5, 20), 6, Vec3(20, 102, 20), 1, 0);
  Sphere sph2 = Sphere(Vec3(15, 5, 10), 6, Vec3(100, 40, 20), 1.3, 1);
  Sphere sph3 = Sphere(Vec3(0,  3, 20), 3, Vec3(12, 32, 123), 1, 0);
  Sphere sph4 = Sphere(Vec3(-8, -3, 20), 2, Vec3(130, 0, 0), 1, 0);

  int numSpheres = 6; 
  for(int i = 1; i < numSpheres; i++){
    for(int k = 1; k < numSpheres; k++){
      Sphere* sph1 = new Sphere(Vec3(18 - k * 6, -4, 25 - i * 6 ), 2, Vec3::randInt(230), 1, 0);
      s.AddShape(sph1);
    }
  }

  Plane pla1 = Plane(Vec3(0, -3, 0), Vec3(0,-6, 100), Vec3(200, 170, 190), 0.4, 0);
  Plane pla2 = Plane(Vec3(0, 0, -4), Vec3(0,0, 40), Vec3(0, 255, 0), 0.4, 0);
  Plane pla3 = Plane(Vec3(-5, 0, 0), Vec3(20, 0, 40), Vec3(255, 0, 0), 0.4, 0);
  Plane pla4 = Plane(Vec3(5, 0, 0), Vec3(-20, 0, 40), Vec3(0, 0, 255), 0.4, 0);
  Plane pla5 = Plane(Vec3(0, 3, 0), Vec3(50, 30, 55), Vec3(125, 125, 180), 0.4, 0);
  //	Plane pla2 = Plane(Vec3(0, 0, -1), Vec3(0, 0, 100), Vec3(46, 220, 32), 0.3, 0);

  //s.AddShape(&sph1);
  //// s.AddShape(&sph2);
  //s.AddShape(&sph3);
  //s.AddShape(&sph4);
  s.AddShape(&pla1);
  s.AddShape(&pla2);
  s.AddShape(&pla3);
  s.AddShape(&pla4);
  s.AddShape(&pla5);
  //	s.AddShape(&pla2);

  Light l2(Vec3(5, 13, -5), Vec3(255, 255, 255), 10000);
  // Light l1(Vec3(10, 20, -10), Vec3(255, 255, 255), 10000);

  // s.AddLight(&l1);
  s.AddLight(&l2);

  // cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3 (0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;

  ImageWriter::write(s.Render());
}

void test() {
  Vec3 a = Vec3(0,0,1); 
  Vec3 b = Vec3(0,1,1); 

  Vec3 out = Vec3::rotate(a,b,PI);
  out.print(); 
}


int main () {
  // sceneA(); 
  sceneB(); 
}
