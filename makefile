all:
	g++ -std=c++11 *.cc -o Raytracer.exe
	./Raytracer.exe
	xdg-open image.ppm

