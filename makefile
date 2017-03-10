all:
	g++ -std=c++11 Raytracer.cc Vec3.cc Shape.cc Sphere.cc Matrix.cc Cylinder.cc -o Raytracer.exe
