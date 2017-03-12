#include "Shape.h"
#include "Constants.h"
#include <cmath>

Shape::Shape(Vec3 surfaceColor, double transparency, double refracInd) : surfaceColor(surfaceColor), 
  transparency(transparency), refInd(refracInd) {
}

Vec3 *Shape::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {

}

double Shape::angle(const Vec3 &point, const Vec3 &rayDirection){

}



Vec3 Shape::Snells(double initIndex, double theta, const Vec3 &normal, 
    const Vec3 &dir)
{
  double theta2 = (refInd / initIndex) * std::sin(theta);
  theta2 = std::asin(theta2);

  //rotate the normal vector in the direction of dir theta2 degrees 
  //might need to fiddle with signs
  Vec3 out = Vec3::rotate(normal, dir, theta2); 
  return out;
}
