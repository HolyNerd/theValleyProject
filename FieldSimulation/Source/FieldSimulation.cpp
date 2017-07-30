#include <FieldSimulation.h>

void FieldSimulation::init() {
	_win_width = 700;
	_win_height = 700;

	Application::init();
}

void FieldSimulation::start() {
	
}

void FieldSimulation::update() {
	static const GLfloat white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	
	glClearBufferfv(GL_COLOR, 0, white);
}

void FieldSimulation::shutdown() {
	
}

MAIN(FieldSimulation)