#include "Vec3.h"
#include "Constants.h"

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

inline Vec3 operator + (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}
inline Vec3 operator - (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}
inline Vec3 operator - (const Vec3 &v) {
	return Vec3(-v.x, -v.y, -v.z);
}

inline Vec3 operator * (const double f, const Vec3 &v) {
	return Vec3(v.x * f, v.y * f, v.z * f);
}
inline Vec3 operator * (const Vec3 &v, const double f) {
	return Vec3(v.x * f, v.y * f, v.z * f);
}
inline Vec3 operator / (const double f, const Vec3 &v) {
	return Vec3(v.x / f, v.y / f, v.z / f);
}
inline Vec3 operator / (const Vec3 &v, const double f) {
	return Vec3(v.x / f, v.y / f, v.z / f);
}

inline double Vec3::X() {
	return x;
}
inline double Vec3::Y() {
	return y;
}
inline double Vec3::Z() {
	return z;
}

inline double Vec3::dot(const Vec3 &v) {
	return x * v.x + y * v.y + z * v.z;
}
