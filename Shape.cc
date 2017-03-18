#include "Shape.h"
#include "Constants.h"
#include "Vec3.h"
#include <cmath>
#include <cassert>

Shape::Shape(Vec3 surfaceColor, double transparency, double refracInd) : surfaceColor(surfaceColor), 
  transparency(transparency), refInd(refracInd) {
}

const int REFRACTION_DEPTH = 5; 
PosDir Shape::Snells(double outsideInd, const Vec3 &hit, const Vec3 &dir, bool entering, int depth)
{
  //cout << "called on " << outsideInd << " entering " << entering << " depth " << depth; 
  //hit.print();
  //dir.print();
  //cout << endl;
  if(depth == 0){
    PosDir out;
    out.dir = dir;
    out.pos = hit;
    return out;
  }

  double n1 = outsideInd;
  double n2 = refInd;

  if(!entering){
    n1 = refInd;
    n2 = outsideInd;
  }

  Vec3 normal = getNormal(hit); 

  double theta1 = angle(hit,dir);

  if(theta1 > PI / 2){
    theta1 = angle(hit,-dir);
  }

  double theta2 = (n1 / n2) * sin(theta1);
  theta2 = std::asin(theta2);

  
  // cout << theta1 << "  " << theta2 << endl;
  if(n1 > n2){
    double critAng = asin(n2 / n1);
    if(abs(theta1) > abs(critAng)){
      //total internal reflection

      Vec3 norm = -getNormal(hit); 
      Vec3 reflVec = Vec3::rotate(dir, norm, PI);

      return Snells(outsideInd, hit, reflVec, false, depth - 1); 
    }
  }

  Vec3 internalDir = Vec3::rotate(dir, Vec3::cross(normal, dir), (theta2 - theta1)); 

  if(!entering){
    PosDir out;
    out.dir = internalDir; 
    out.pos = hit;
    return out;
  }

  Vec3 *internalIntP = selfIntersection(hit, internalDir);
  if(internalIntP == nullptr){
    PosDir out;
    out.dir = Vec3(1,0,0);//Vec3::rotate(internalDir, Vec3::cross(normal, dir), (2 * theta1));
    out.pos = Vec3(0,0,0);
    return out;
  }

  Vec3 internalInt = *internalIntP;
  delete internalIntP;

  //recrusive
  return Snells(outsideInd, internalInt, internalDir, false, depth - 1); 


  //Vec3 newnorm = getNormal(internalInt); 
  //critAng = asin(n1 / n2);
  //theta1 = angle(internalInt, -internalDir);

  //if(theta1 >= critAng){
    //PosDir out;
    
    //Vec3 reflectedInt = getReflectionDir(internalInt, internalDir);
    //out = Snells(outsideInd, internalInt,reflectedInt, false); 
    //return out;
  //}

  //theta2 = (n2 / n1) * sin(theta1);
  //theta2 = std::asin(theta2);

  //PosDir out; 
  //out.dir = Vec3::rotate(internalDir, Vec3::cross(-internalDir, newnorm), -(theta2 - theta1)); 
  //out.pos = internalInt;

  //return out;
}

double Shape::getFresK(double initInd, const Vec3 &hit, const Vec3 &dir, bool entering){
  //for n1 to n2
  double n2 = refInd;
  double n1 = initInd;
  if(!entering){
    n2 = initInd;
    n1 = refInd;
  }

  double ang = angle(hit,dir);
  if(ang > PI / 2){
    ang = angle(hit,-dir);
  }
  double ang2 = (n1 / n2) * sin(ang);
  ang2 = std::asin(ang2);

  if(n1 > n2){
    double critAng = asin(n2 / n1);
    if(abs(ang) > abs(critAng)){
      return 1; 
    }
  }
  double Rs = (n2 * cos(ang) - n1 * cos(ang2)) / (n2 * cos(ang) + n1 * cos(ang2)); 
  Rs = Rs * Rs;

  double Rp = (n1 * cos(ang2) - n2 * cos(ang)) / (n1 * cos(ang2) + n2 * cos(ang));
  Rp = Rp * Rp;
  
  double out = 1.0 - (Rs + Rp) / 2.0;
  return out * out * out * out * out * out; 
}


Vec3 Shape::getReflectionDir(const Vec3 &hit, const Vec3 &dir){
  Vec3 norm = getNormal(hit); 
  Vec3 reflVec = -Vec3::rotate(dir, norm, PI);
}



