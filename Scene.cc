#include "Vec3.h"
#include "Camera.h"
#include "Shape.h"
#include "Scene.h"
#include "Sphere.h"
#include "Constants.h"
#include <algorithm>
#include <iostream>
#include <cmath>

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
      image[i][k] = Vec3(std::min((int)round(out.X()), 255), std::min((int)round(out.Y()), 255), std::min((int)round(out.Z()), 255));
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
      if(shapes[j]->isTransp()){
        continue;
      }
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

const Vec3 BACKGROUND_COLOR(255,255,255);

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
    return BACKGROUND_COLOR; 
  }



  // specular lighting
  double ka = 0.1; 
  double kd = 0.8; 
  double ks = 0.22; 

  Vec3 ambient = shapes[objInd]->getSurfaceColor() * ka; 

  Vec3 diffuse = Vec3(0,0,0);
  Vec3 specular = Vec3(0,0,0);

  int SAMPLES = 200; 
  double SPEC_N = 10;
  for (int i = 0; i < (int)light.size(); i++) {
    for(int k = 0; k<SAMPLES; k++){

      Vec3 ndir = (light[i]->getPos() + Vec3::random(1.5) - *hitPoint).normalize();


      bool objInWay = false; 
      // check if something else is in the way
      for (int j = 0; j < (int)shapes.size(); j++) {
        auto inter = shapes[j]->intersectionPoint(*hitPoint, ndir);
        if (inter != nullptr) {
          objInWay = true;
          break;
        }
      }
      if(objInWay) continue;
      diffuse = diffuse + shapes[objInd]->getSurfaceColor() * std::fmax(Vec3::dot((shapes[objInd]->getNormal(*hitPoint)).normalize()
          ,(-(*hitPoint) + light[i]->getPos()).normalize()) * light[i]->getIntensity(*hitPoint), 0) ;


      Vec3 R = shapes[objInd]->getReflectionDir(*hitPoint, ndir * -1);
      specular = specular + Vec3(255,255,255) * std::pow(std::fmax(Vec3::dot(R.normalize(), dir.normalize() * -1), 0), SPEC_N);
    }
  }

  Vec3 col = (diffuse * kd + specular * ks + ambient * ka) * (1.0 / SAMPLES);


  Vec3 fresCol = Vec3(0,0,0); if(shapes[objInd]->isTransp()) { 
    Vec3 reflDir = shapes[objInd]->getReflectionDir(*hitPoint,dir); 
    badInd = objInd;
    Vec3 reflectionCol = Trace(*hitPoint, reflDir, depth--);

    //refraction
    PosDir refrac = shapes[objInd]->Snells(1.0, *hitPoint, dir);
    badInd = objInd;
    Vec3 refractionCol = Trace(refrac.pos, refrac.dir, depth--);

    double fresK = shapes[objInd]->getFresK(1.0, *hitPoint, dir); 
    fresK = 0.8;
    fresCol = (refractionCol * fresK + reflectionCol *  (1 - fresK));
  }

  if(Scene::inShadow(*hitPoint)) {
    // col = ambient; 
  }

  delete hitPoint;

  double k = shapes[objInd]->getTransp(); 
  return col * (1 - k) + fresCol * k;
}

Vec3 Scene::Trace(Vec3& pos, Vec3& dir) {
  return Trace(pos,dir,MAX_DEPTH); 
}
