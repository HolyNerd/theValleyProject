#include <FieldSimulation.h>

void FieldSimulation::init() {
	_win_width = 700;
	_win_height = 700;

	Application::init();
}

void FieldSimulation::start() {
	
}

void FieldSimulation::update() {
	static const GLfloat bhColor[] = { 0.2f, 0.4f, 0.7f, 1.0f };
	
	glClearBufferfv(GL_COLOR, 0, bhColor);
}

void FieldSimulation::shutdown() {
	
}

