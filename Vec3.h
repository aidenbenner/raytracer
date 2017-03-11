#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <cstdio>
#include "Constants.h"

class Vec3 {
public:
Vec3();
Vec3(double x, double y, double z);

bool operator == (const Vec3 &v) const;
bool operator != (const Vec3 &v) const;
Vec3 operator + (const Vec3 &v) const;
Vec3 operator - (const Vec3 &v) const;
Vec3 operator - () const;
Vec3 operator * (const double &f) const;
Vec3 operator / (const double &f) const;

static double dot(const Vec3 &a, const Vec3 &b);
static Vec3 cross(const Vec3 &a, const Vec3 &b);
static Vec3 proj(const Vec3 &a, const Vec3 &b);

double X() const;
double Y() const;
double Z() const;

double length() const;
Vec3 normalize();

private:
double x, y, z;
};

#endif
