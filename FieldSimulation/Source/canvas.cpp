#include <canvas.h>

Canvas::Canvas() {

}

Canvas::Canvas(int elementsAmount) 
	: canvas(elementsAmount)
{

}


void Canvas::add(int amount) {
	Charge* charge = new Charge[amount];
	
	for(int i = 0; i < amount; i++)
		canvas.push_back(charge[i]);
	
}

void Canvas::Draw() {
	for(int i = 0; i < canvas.size(); i++)
		canvas[i].Draw();
}

Charge& Canvas::operator[](int index) {
	return canvas[index];
}

int Canvas::getSize() {
	return canvas.size();
}

Charge* Canvas::getPointer(int index) {
	Charge* temp = &(canvas[index]);
	return temp;
}