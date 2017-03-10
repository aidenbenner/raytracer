#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <cstdio>

class Vec3 {
public:
Vec3();
Vec3(double x, double y, double z);

friend std::ostream &operator << (std::ostream &os, const Vec3 &v);

double X() const;
double Y() const;
double Z() const;

double length() const;
Vec3 normalize();

private:
double x, y, z;
};

bool operator == (const Vec3 &a, const Vec3 &b);
bool operator != (const Vec3 &a, const Vec3 &b);
Vec3 operator + (const Vec3 &a, const Vec3 &b);
Vec3 operator - (const Vec3 &a, const Vec3 &b);
Vec3 operator - (const Vec3 &v);

Vec3 operator * (const double f, const Vec3 &v);
Vec3 operator * (const Vec3 &v, const double f);
Vec3 operator / (const double f, const Vec3 &v);
Vec3 operator / (const Vec3 &v, const double f);

double dot(const Vec3 &a, const Vec3 &b);
Vec3 cross(const Vec3 &a, const Vec3 &b);
Vec3 proj(const Vec3 &a, const Vec3 &b);

#endif
