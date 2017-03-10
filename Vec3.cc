#include "Vec3.h"
#include "Constants.h"

inline Vec3::Vec3() : x(0), y(0), z(0) {
}
inline Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {
}

inline std::ostream& Vec3::operator << (std::ostream &os) const {
	os << '[' << x << ' ' << y << ' ' << z << ']';
	return os;
}

inline bool Vec3::operator == (const Vec3 &v) const {
	return std::fabs(x - v.X()) <= EPS
	       && std::fabs(y - v.Y()) <= EPS
	       && std::fabs(z - v.Z()) <= EPS;
}

inline bool Vec3::operator != (const Vec3 &v) const {
	return !(Vec3(x, y, z) == v);
}

inline Vec3 Vec3::operator + (const Vec3 &v) const {
	return Vec3(x + v.X(), y + v.Y(), z + v.Z());
}
inline Vec3 Vec3::operator - (const Vec3 &v) const {
	return Vec3(x - v.X(), y - v.Y(), z - v.Z());
}
inline Vec3 Vec3::operator - () const {
	return Vec3(-x, -y, -z);
}

inline Vec3 Vec3::operator * (const double f) const {
	return Vec3(x * f, y * f, z * f);
}
inline Vec3 Vec3::operator / (const double f) const {
	return Vec3(x / f, y / f, z / f);
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

inline double Vec3::dot(const Vec3 &a, const Vec3 &b) {
	return a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z();
}
inline Vec3 Vec3::cross(const Vec3 &a, const Vec3 &b) {
	return Vec3(a.Y() * b.Z() - a.Z() * b.Y(), a.Z() * b.X() - a.X() * b.Z(), a.X() * b.Y() - a.Y() * b.Z());
}

inline Vec3 Vec3::proj(const Vec3 &a, const Vec3 &b) {
	return b * Vec3::dot(a, b) / Vec3::dot(b, b);
}
