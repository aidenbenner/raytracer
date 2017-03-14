#include "Shape.h"
#include "Constants.h"
#include "Vec3.h"
#include <cmath>
#include <cassert>

Shape::Shape(Vec3 surfaceColor, double transparency, double refracInd) : surfaceColor(surfaceColor), 
  transparency(transparency), refInd(refracInd) {
}

Vec3 *Shape::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {

}

double Shape::angle(const Vec3 &point, const Vec3 &rayDirection){

}


PosDir Shape::Snells(double initIndex, const Vec3 &hit, const Vec3 &dir)
{
  refInd = 1.9;
  double critAng = asin( refInd / initIndex );

  Vec3 normal = getNormal(hit); 
  double theta1 = angle(hit,dir);
  assert(theta1 >= 0 - EPS); 
  if(theta1 >= critAng + 30 * EPS){

    PosDir out;
    out.dir = Vec3(0,0,-1); 
    out.pos = Vec3(0,0,0);
    return out;

    out.dir = -Vec3::rotate(normal, Vec3::cross(normal, dir), -theta1); 
    out.pos = hit;
    return out;
  }


  double theta2 = ((double)initIndex / (double)refInd) * sin(theta1);
  theta2 = std::asin(theta2);

  Vec3 internalDir = -Vec3::rotate(normal, Vec3::cross(normal, dir), -theta2); 


  // careful of memory leak  
  Vec3 *internalIntP = intersectionPoint(hit + dir * 30 * EPS, internalDir);
  if(internalIntP == nullptr){
    PosDir out;
    out.dir = internalDir;
    out.pos = hit;
    return out;
  }


  Vec3 internalInt = *internalIntP;
  delete internalIntP;

  Vec3 newnorm = getNormal(internalInt); 


  critAng = asin( initIndex / refInd);
  theta1 = angle(internalInt, internalDir);
  if(theta1 >= critAng){
    PosDir out;
    out.dir = Vec3(0,0,-1); 
    out.pos = Vec3(0,0,0);
    return out;
  }


  theta2 = (refInd / initIndex) * sin(theta1);
  theta2 = std::asin(theta2);

  //theta2 is nan for some reason

  PosDir out; 
  out.dir = -Vec3::rotate(newnorm, Vec3::cross(internalDir, newnorm), theta2); 
  out.pos = internalInt;
  return out;
}
