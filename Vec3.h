#ifndef VEC3_H
#define VEC3_H

double EPS = 1e-9;

class Vec3 {
public:
Vec3();
Vec3(double x, double y, double z);

friend bool operator == (const Vec3 &a, const Vec3 &b);
friend bool operator != (const Vec3 &a, const Vec3 &b);

// Vec3 operator + (const Vec3 &v);
// Vec3 operator - (const Vec3 &v);
// Vec3 operator * (const double &f);
// Vec3 operator * (const Vec3 &v);
// Vec3 operator - ();

friend std::ostream &operator << (std::ostream &os, const Vec3 &v);

private:
double x, y, z;
};

#endif
