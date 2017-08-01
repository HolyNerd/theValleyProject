#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include <charge.h>
class Canvas {
public:
	Canvas();
	Canvas(int);

	int getSize();
	Charge* getPointer(int index);

	void add(int);
	void Draw();

	Charge& operator[](int index);
private:
	std::vector<Charge> canvas;
};

#endif