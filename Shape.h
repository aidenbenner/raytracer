#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"
#include "Matrix.h"
#include "Constants.h"

class Shape {

  public:
    Shape(Vec3 surfaceColor, double transparency, double refraction);
    virtual Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) =0;
    virtual double angle(const Vec3 &point, const Vec3 &rayDirection) =0; 
    virtual Vec3 getNormal(const Vec3 &hitpoint) =0; 
    virtual Vec3 *selfIntersection(const Vec3 &rayOrigin, const Vec3 &rayDirection) =0; 

    Vec3 getSurfaceColor(){
      return surfaceColor;
    }

    double getTransp() { 
      return transparency;
    }

    bool isTransp() {
      return (fabs(transparency) > 0);
    }

    double getRefInd() {
      return refInd;
    }

    PosDir Snells(double initIndex, const Vec3 &hit, const Vec3 &dir, bool entering = true, int depth = MAX_REFRACTION_DEPTH);
    double getFresK(double initIndex, const Vec3 &hit, const Vec3 &dir, bool entering = true); 

    Vec3 getReflectionDir(const Vec3 &hit, const Vec3 &dir); 

  protected: 
    Vec3 surfaceColor;
    double transparency;
    double refInd;

};

#endif
