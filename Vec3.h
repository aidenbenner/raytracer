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

double X();
double Y();
double Z();

double dot(const Vec3 &v);

private:
double x, y, z;
};

#endif
