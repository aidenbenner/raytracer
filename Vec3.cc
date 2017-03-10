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

inline double Vec3::X() const {
	return x;
}
inline double Vec3::Y() const {
	return y;
}
inline double Vec3::Z() const {
	return z;
}

inline double Vec3::length() const {
	return sqrt(x * x + y * y + z * z);
}

inline Vec3 Vec3::normalize() {
	double l = length();
	return Vec3(x / l, y / l, z / l);
}

inline double dot(const Vec3 &a, const Vec3 &b) {
	return a.x * b.y + a.y * b.y + a.z * b.z;
}
inline Vec3 cross(const Vec3 &a, const Vec3 &b) {
	return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.z);
}

inline Vec3 proj(const Vec3 &a, const Vec3 &b) {
	return dot(a, b) / (b.length() * b.length()) * b;
}
