#include "ImageWriter.h"
#include <cmath>

void ImageWriter::write(vector<vector<Vec3> > image) {

	int width = image[0].size();
	int height = image.size();

	// dont know what the flags mean
	std::ofstream ofs("./image.ppm", std::ios::out | std::ios::binary);

	// sets the dimensions of the image
	ofs << "P6\n" << width << " " << height << "\n255\n";

	// outputs color of each pixel
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
      double r = image[i][j].X();
      double g = image[i][j].Y();
      double b = image[i][j].Z();

			ofs << (unsigned char) (r) << (unsigned char) (g) << (unsigned char) (b);
		}
	}

	ofs.close();
}
