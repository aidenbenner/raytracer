#include "Vec3.h"
#include "Camera.h"
#include "Shape.h"
#include "Scene.h"
#include "Sphere.h"

vector<vector<Vec3> > Scene::Render() {
	int height = cam.GetSHeight();
	int width = cam.GetSWidth();

	double ph = cam.GetPHeight();
	double pw = cam.GetPWidth();

	Vec3 pos = cam.GetPos();
	Vec3 dir = cam.GetDir();

	vector<vector<Vec3> > image;
	image.resize(height);
	for(int i = 0; i<height; i++) {
		double per = (double) i / height;
		double y = per * ph - ph/2;
		image[i].resize(width);
		for(int k = 0; k<width; k++) {
			double hper = (double)k / width;
			double x = hper * pw - pw/2;
			double z = cam.GetPDist();

			Vec3 ray(x,y,z);
			image[i][k] = Trace(dir, ray);
		}
	}
	return image;
}

// True if it hits light
bool Scene::ShadowTrace(Vec3& pos) {
	for (int i = 0; i < light.size(); i++) {
		Vec3 ndir = light[i]->getPos() - pos;
		bool ret = true;

		for (int j = 0; j < shapes.size(); j++) {

			if (shapes[j]->intersectionPoint(pos, ndir) != nullptr) {
				ret = false;
			}
		}

		if (ret) {
			return true;
		}
	}
	return false;
}

// Returns pixel value
Vec3 Scene::Trace(Vec3& dir, Vec3& pos) {

	// Cast dir
	Vec3* hitPoint = nullptr;
	int objInd = 0;
	double minDist = INF;

	for(int i = 0; i< shapes.size(); i++) {
		Vec3* point = shapes[i]->intersectionPoint(pos, dir);

		//check if we hit
		if(point == nullptr) {
			continue;
		}

		double dist = (*point - pos).length();
		if(dist < minDist) {
			objInd = i;
			minDist = dist;
			hitPoint = point;
		}
		else{
			delete point;
		}
	}

	if(hitPoint == nullptr) {
		return Vec3(255,255,255); // white
	}

	Vec3 col = Scene::ShadowTrace(*hitPoint) ? shapes[objInd]->getSurfaceColor() : Vec3(0, 0, 0);

	return col;
}
