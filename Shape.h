#ifndef SHAPE_H
#define SHAPE_H

#include "Vec3.h"
#include "Matrix.h"
#include "Constants.h"

class Shape {

  public:
    Shape(Vec3 surfaceColor, double transparency, double refraction);
    virtual Vec3 *intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection);
    virtual double angle(const Vec3 &point, const Vec3 &rayDirection);
    Vec3 getSurfaceColor(){
      return surfaceColor;
    }

    double getTransp() { 
      return transparency;
    }

    double getRefInd() {
      return refInd;
    }

  Vec3 Snells(double initIndex, double theta, const Vec3 &normal, 
      const Vec3 &dir);

  private:
    Vec3 surfaceColor;
    double transparency;
    double refInd;

};

#endif
