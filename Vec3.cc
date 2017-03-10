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
	return std::fabs(a.X() - b.X()) <= EPS
	       && std::fabs(a.Y() - b.Y()) <= EPS
	       && std::fabs(a.Z() - b.Z()) <= EPS;
}

inline bool operator != (const Vec3 &a, const Vec3 &b) {
	return !(a == b);
}

inline Vec3 operator + (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}
inline Vec3 operator - (const Vec3 &a, const Vec3 &b) {
	return Vec3(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}
inline Vec3 operator - (const Vec3 &v) {
	return Vec3(-v.X(), -v.Y(), -v.Z());
}

inline Vec3 operator * (const double f, const Vec3 &v) {
	return Vec3(v.X() * f, v.Y() * f, v.Z() * f);
}
inline Vec3 operator * (const Vec3 &v, const double f) {
	return Vec3(v.X() * f, v.Y() * f, v.Z() * f);
}
inline Vec3 operator / (const double f, const Vec3 &v) {
	return Vec3(v.X() / f, v.Y() / f, v.Z() / f);
}
inline Vec3 operator / (const Vec3 &v, const double f) {
	return Vec3(v.X() / f, v.Y() / f, v.Z() / f);
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
	return a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z();
}
inline Vec3 cross(const Vec3 &a, const Vec3 &b) {
	return Vec3(a.Y() * b.Z() - a.Z() * b.Y(), a.Z() * b.X() - a.X() * b.Z(), a.X() * b.Y() - a.Y() * b.Z());
}

inline Vec3 proj(const Vec3 &a, const Vec3 &b) {
	return dot(a, b) / dot(b, b) * b;
}
