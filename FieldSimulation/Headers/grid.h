
#ifndef GRID_H
#define GRID_H

#include <object.h>
#include <color.h>

class Grid : public Object{
public:
	Grid(float offset, int width, int height);
	void setColor(float, float, float);
private:
	float offset;
	Color gridColor;
};

#endif