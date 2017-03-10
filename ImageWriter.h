#ifndef IMAGE_WRITER_H
#define IMAGE_WRITER_H

#include "Vec3.h"
#include <vector>
#include <fstream>

using namespace std;

class ImageWriter {
private:
public:
	static void writer(vector<vector<Vec3> > image);
};
#endif