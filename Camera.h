
#ifndef CAMERA_H
#define CAMERA_H

#include "Vec3.h"


class Camera {
  public: 
    Camera(Vec3 pos, Vec3 dir, double width, double height, double dist): 
      pos(pos), dir(dir), pwidth(width), pheight(height),  pdist(dist){  }

  private:  
    Vec3 pos; 
    Vec3 dir;
    double pwidth;
    double pdist; 
    double pheight;
};

#endif
