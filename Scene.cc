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

  double xAng = PI / 12;
  double yAng = 0;

  //rotates about z axis
  double zAng = 0;

  double fov = PI/6; 
  double angle = tan(0.5 * fov); 
  double aspect = width / height;

  vector<vector<Vec3> > image;
  image.resize(height);

  for(int i = 0; i<height; i++) {
    double per = (double) i / height;
    double y = ((2.0 * i / height) - 1) * angle;//per * ph - ph / 2;

    image[i].resize(width);

    for(int k = 0; k<width; k++) {
      double hper = (double)k / width;
      double x = ((2.0 * k / width) - (double)1) * angle * aspect;// hper * pw - pw/2;
      double z = -1;//cam.GetPDist();



      Vec3 ray = (Vec3(x, y, z) - pos).normalize();
      ray = -ray;

      //should be faster if we implemented a rotation matrix but that can wait 
      ray = Vec3::rotate(ray, Vec3(1,0,0), xAng); 
      ray = Vec3::rotate(ray, Vec3(0,1,0), yAng); 
      ray = Vec3::rotate(ray, Vec3(0,0,1), zAng); 

      

      
      Vec3 out = Trace(pos, ray);
      image[i][k] = Vec3(round(out.X()), round(out.Y()), round(out.Z()));
    }
  }
  return image;
}

// True if it hits light
bool Scene::inShadow(Vec3& pos) {
  Vec3* inter;
  for (int i = 0; i < light.size(); i++) {
    Vec3 ndir = (light[i]->getPos() - pos).normalize();
    bool ret = false;

    for (int j = 0; j < shapes.size(); j++) {
      inter = shapes[j]->intersectionPoint(pos, ndir);
      if (inter != nullptr) {
        ret = true;
        delete inter;
      }
    }

    if (!ret) {
      return false;
    }
  }
  return true;
}

// Returns pixel value


int badInd = -1; 


Vec3 Scene::Trace(Vec3& pos, Vec3& dir, int depth) {

  if(depth <= 0){ 
    return Vec3(0,255,0); //so we don't confuse with shadows for rn make this green 
  }

  // Cast dir
  Vec3* hitPoint = nullptr;
  int objInd = 0;
  double minDist = INF;

  for(int i = 0; i< shapes.size(); i++) {
    if(i == badInd) continue;
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

  badInd = -1; 
  if(hitPoint == nullptr) {
    return Vec3(255,255,255); // white
  }

  Vec3 col = shapes[objInd]->getSurfaceColor() * Vec3::dot((shapes[objInd]->getNormal(*hitPoint)).normalize(),(-(*hitPoint) + light[0]->getPos()).normalize());

  //Refr
  if(abs(shapes[objInd]->getTransp()) > EPS){
    PosDir refrac = shapes[objInd]->Snells(1.0, *hitPoint, dir);
    badInd = objInd;
    Vec3 col2 = Trace(refrac.pos, refrac.dir, depth--);
    return col2 * 0.9;
  }

  //Vec3 refract = Trace(*hitPoint,dir,depth - 1);
  //col = col * 0.1 + refract * 0.9; 
  

  //why is this ! in shadow !? 
  if(Scene::inShadow(*hitPoint)) {
    col = Vec3(0,0,0); 
  }



  delete hitPoint;
  return col;
}

Vec3 Scene::Trace(Vec3& pos, Vec3& dir) {
  return Trace(pos,dir,MAX_DEPTH); 
}
