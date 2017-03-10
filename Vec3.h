#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <cstdio>

class Vec3 {
public:
Vec3();
Vec3(double x, double y, double z);

friend bool operator == (const Vec3 &a, const Vec3 &b);
friend bool operator != (const Vec3 &a, const Vec3 &b);
friend Vec3 operator + (const Vec3 &a, const Vec3 &b);
friend Vec3 operator - (const Vec3 &a, const Vec3 &b);
friend Vec3 operator - (const Vec3 &v);

friend Vec3 operator * (const double f, const Vec3 &v);
friend Vec3 operator * (const Vec3 &v, const double f);
friend Vec3 operator / (const double f, const Vec3 &v);
friend Vec3 operator / (const Vec3 &v, const double f);

friend std::ostream &operator << (std::ostream &os, const Vec3 &v);

double X() const;
double Y() const;
double Z() const;

double length() const;
Vec3 normalize();

friend double dot(const Vec3 &a, const Vec3 &b);
friend Vec3 cross(const Vec3 &a, const Vec3 &b);
friend Vec3 proj(const Vec3 &a, const Vec3 &b);

private:
double x, y, z;
};

#endif
