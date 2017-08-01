
#include <grid.h>

Grid::Grid(float offset, int width, int height) {
	type = GL_LINES;

	float norm = offset / width;
	int amount_w = 2 / norm;
	int amount_h = 2 / (offset / height);

	va.add(amount_w*2 + amount_h*2);

	for(float off = -1, i = 0; i < amount_w*2; i+=2, off += norm) {
		va[i].setCoordinate(off, 1.0f, 0.0f);
		va[i+1].setCoordinate(off, -1.0f, 0.0f);
	}

	norm = offset / height;

	for(float off = -1, i = amount_w*2; i < va.getAmount(); i+=2, off += norm) {
		va[i].setCoordinate(1.0f, off, 0.0f);
		va[i+1].setCoordinate(-1.0f, off, 0.0f);
	}

	gridColor.r = 220/255.0f;
	gridColor.b = 220/255.0f;
	gridColor.g = 220/255.0f;
	
	for(int i = 0; i < va.getAmount(); i++) 
		va[i].setColor(gridColor.r, gridColor.g, gridColor.b);
}