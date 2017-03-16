#include "Vec3.h"

Vec3::Vec3() : x(0), y(0), z(0) {
}

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {
}

std::ostream& operator << (std::ostream &os, const Vec3 &v) {
	os << '[' << v.X() << ' ' << v.Y() << ' ' << v.Z() << ']';
	return os;
}

bool Vec3::operator == (const Vec3 &v) const {
	return std::fabs(x - v.X()) <= EPS
	       && std::fabs(y - v.Y()) <= EPS
	       && std::fabs(z - v.Z()) <= EPS;
}

bool Vec3::operator != (const Vec3 &v) const {
	return !(Vec3(x, y, z) == v);
}

Vec3 Vec3::operator + (const Vec3 &v) const {
	return Vec3(x + v.X(), y + v.Y(), z + v.Z());
}
Vec3 Vec3::operator - (const Vec3 &v) const {
	return Vec3(x - v.X(), y - v.Y(), z - v.Z());
}
Vec3 Vec3::operator - () const {
	return Vec3(-x, -y, -z);
}

Vec3 Vec3::operator * (const double &f) const {
	return Vec3(x * f, y * f, z * f);
}
Vec3 Vec3::operator / (const double &f) const {
	return Vec3(x / f, y / f, z / f);
}

double Vec3::X() const {
	return x;
}
double Vec3::Y() const {
	return y;
}
double Vec3::Z() const {
	return z;
}

//rotates v theta radians around the direction give by axisOfRot (should be a unit vector but we convert)
//follows right hand rule
//https://en.wikipedia.org/wiki/Rodrigues'_rotation_formula
Vec3 Vec3::rotate(const Vec3& v, const Vec3& axisOfRot, double theta){
  Vec3 k = axisOfRot.normalize(); 
  Vec3 out = v * std::cos(theta) + Vec3::cross(k,v) * std::sin(theta) 
    + (k * (Vec3::dot(k,v))) * (1.0 - std::cos(theta));
  return out;
}

double Vec3::length() const {
	return sqrt(x * x + y * y + z * z);
}

void Vec3::print() const{
  std::cout << "[" << x << " " << y << " " << z << "]"; 
}

Vec3 Vec3::normalize() const{
	double l = length();
	return Vec3(x / l, y / l, z / l);
}




double Vec3::dot(const Vec3 &a, const Vec3 &b) {
	return a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z();
}
Vec3 Vec3::cross(const Vec3 &a, const Vec3 &b) {
	return Vec3(a.Y() * b.Z() - a.Z() * b.Y(), a.Z() * b.X() - a.X() * b.Z(), a.X() * b.Y() - a.Y() * b.Z());
}

Vec3 Vec3::proj(const Vec3 &a, const Vec3 &b) {
	return b * Vec3::dot(a, b) / Vec3::dot(b, b);
}
