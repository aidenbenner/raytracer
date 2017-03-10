#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "Vec3.h"

inline Vec3::Vec3() : x(0), y(0), z(0) {
}
inline Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {
}

inline std::ostream &operator << (std::ostream &os, const Vec3 &v) {
	os << '[' << v.x << ' ' << v.y << ' ' << v.z << ']';
	return os;
}

inline bool operator == (const Vec3 &a, const Vec3 &b) {
	return std::fabs(a.x - b.x) <= EPS
	       && std::fabs(a.y - b.y) <= EPS
	       && std::fabs(a.z - b.z) <= EPS;
}

inline bool operator != (const Vec3 &a, const Vec3 &b) {
	return !(a == b);
}
//
// Vec3 operator + (const Vec3 &v) {
//      return Vec3(x + v.x, y + v.y, z + v.z);
// }
// Vec3 operator - (const Vec3 &v) {
//      return Vec3(x + v.x, y + v.y, z + v.z);
// }
// Vec3 operator * (const double &f) {
//      return Vec3(x * f, y * f, z * f);
// }
// Vec3 operator * (const Vec3 &v) {
//
// }
// Vec3 operator - ();
