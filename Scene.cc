#include "Vec3.h"
#include "Camera.h"
#include "Shape.h"
#include "Scene.h"

void Scene::Render() {
  int height = cam.GetSHeight();
  int width = cam.GetSWidth(); 

  double ph = cam.GetPHeight();
  double pw = cam.GetPWidth();

  Vec3 pos = cam.GetPos(); 
  Vec3 dir = cam.GetDir(); 

  vector<vector<Vec3>> image;
  image.resize(height);
  for(int i = 0; i<height; i++){
    double per = (double)i / height;
    double y = per * ph - ph/2;
    image[i].resize(width);
    for(int k = 0; k<width; k++){
      double hper = (double)k / width;
      double x = hper * pw - pw/2;
      double z = cam.GetPDist();

      Vec3 ray(x,y,z); 
      image[i][k] = Trace(ray,pos);
    }
  }
}


//returns pixel value
Vec3 Scene::Trace(Vec3& dir, Vec3& pos) {

  //cast dir
  Vec3* hitPoint = nullptr;
  int objInd = 0; 
  double minDist = INF; 
  
  for(int i = 0; i<shapes.size(); i++){
    Vec3* point = intersectionPoint(dir, pos); 

    //check if we hit
    if(point == nullptr){
      continue;
    }

    double dist = (point - pos).length(); 
    if(dist < minDist){
      objInd = i; 
      minDist = dist;
      hitPoint = point;
    }
    else{ 
      delete point;
    }
  }

  if(hitPoint == nullptr){
    return Vec3(255,255,255); //background is black
  }
  Vec3 col = shapes[objInd]->surfaceColor;
  delete shapes[objInd]; 
  return col;
}
