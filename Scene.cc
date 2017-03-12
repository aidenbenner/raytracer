#include "Vec3.h"
#include "Camera.h"
#include "Shape.h"
#include "Scene.h"
#include "Sphere.h"
#include "Constants.h"

vector<vector<Vec3> > Scene::Render() {
  int height = cam.GetSHeight();
  int width = cam.GetSWidth();

  double ph = cam.GetPHeight();
  double pw = cam.GetPWidth();

  Vec3 pos = cam.GetPos();
  Vec3 dir = cam.GetDir();
  dir = dir.normalize(); 



  
  double xAng = 0;
  double yAng = 0;

  //rotates about z axis
  double zAng = 3.14159;


  vector<vector<Vec3> > image;
  image.resize(height);

  for(int i = 0; i<height; i++) {
    double per = (double) i / height;
    double y = per * ph - ph / 2;

    image[i].resize(width);

    for(int k = 0; k<width; k++) {
      double hper = (double)k / width;
      double x = hper * pw - pw/2;
      double z = cam.GetPDist();

      Vec3 ray = (Vec3(x, y, z) - pos).normalize();

      ray = Vec3::rotate(ray, Vec3(1,0,0), xAng); 
      ray = Vec3::rotate(ray, Vec3(0,1,0), yAng); 
      ray = Vec3::rotate(ray, Vec3(0,0,1), zAng); 

      image[i][k] = Trace(pos, ray);
    }
  }
  return image;
}

// True if it hits light
bool Scene::inShadow(Vec3& pos) {
  Vec3* inter;
  for (int i = 0; i < light.size(); i++) {
    Vec3 ndir = (light[i]->getPos() - pos).normalize();
    bool ret = true;

    for (int j = 0; j < shapes.size(); j++) {
      inter = shapes[j]->intersectionPoint(pos, ndir);
      if (inter != nullptr) {
        ret = false;
        delete inter;
      }
    }

    if (ret) {
      return true;
    }
  }
  return false;
}

// Returns pixel value


Vec3 Scene::Trace(Vec3& pos, Vec3& dir, int depth) {
  if(depth <= 0){ 
    return Vec3(0,255,0); //so we don't confuse with shadows for rn make this green 
  }

  // Cast dir
  Vec3* hitPoint = nullptr;
  int objInd = 0;
  double minDist = INF;

  for(int i = 0; i< shapes.size(); i++) {
    Vec3* point = shapes[i]->intersectionPoint(pos, dir);

    // Check if we hit
    if(point == nullptr) {
      continue;
    }

    double dist = (*point - pos).length();
    if (dist < minDist) {
      objInd = i;
      minDist = dist;
      hitPoint = point;
    } else {
      delete point;
    }
  }

  if(hitPoint == nullptr) {
    return Vec3(255,255,255); // white
  }



  Vec3 col = shapes[objInd]->getSurfaceColor() * cos(shapes[objInd]->angle(*hitPoint, *hitPoint - light[0]->getPos()));
  //Vec3 refract = Trace(*hitPoint,dir,depth - 1);
  //col = col * 0.1 + refract * 0.9; 
  

  //why is this ! in shadow !? 
  if(!Scene::inShadow(*hitPoint)) {
    col = Vec3(0,0,0); 
  }



  delete hitPoint;
  return col;
}

Vec3 Scene::Trace(Vec3& pos, Vec3& dir) {
  return Trace(pos,dir,MAX_DEPTH); 
}
