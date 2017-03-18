#ifndef UTIL_H
#define UTIL_H


namespace Util{

  static double clamp(double val, double max, double min){
    if(val > max){
      return max;
    }
    if(val < min){
      return min;
    }
    return val;
  }


}




#endif

