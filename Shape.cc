#include "Shape.h"
#include "Constants.h"

Shape::Shape(Vec3 surfaceColor, double transparency, double refracInd) : surfaceColor(surfaceColor), 
  transparency(transparency), refInd(refracInd) {
}

Vec3 *Shape::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {

}

double Shape::angle(const Vec3 &point, const Vec3 &rayDirection){

}
