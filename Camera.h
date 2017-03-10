
#ifndef CAMERA_H
#define CAMERA_H

#include "Vec3.h"


class Camera {
  public: 
    Camera(Vec3 pos, Vec3 dir, double width, double height, double dist, int screenh, int screenw): 
      pos(pos), dir(dir), pwidth(width), pheight(height),  pdist(dist), sheight(screenh), swidth(screenw){  }

    inline Vec3 GetPos(){
      return pos;
    }

    inline Vec3 GetDir(){
      return dir;
    }

    inline double GetPDist(){
      return pwidth;
    }

    inline double GetPWidth(){
      return pwidth;
    } 

    inline double GetPHeight(){
      return pheight;
    }

    inline double GetSHeight(){
      return sheight;
    }

    inline double GetSWidth(){
      return swidth;
    }

  private:  
    Vec3 pos; 
    Vec3 dir;
    double pwidth;
    double pdist; 
    double pheight;
    int sheight;
    int swidth;
};

#endif
