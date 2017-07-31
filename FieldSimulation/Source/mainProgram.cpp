#include <mainProgram.h>

void mainProgram::init() {

	_win_width = 900;
	_win_height = 800;

	Application::init();
}

void mainProgram::start() {
	GLfloat color[] = { 0.0, 0.0, 0.0, 0.0 };
	glClearBufferfv(GL_COLOR, 0, color);
	o = new Object(3);

	o->setVertexCoordinate(0, 0.5f, 0.5f, 0.5f);
	o->setVertexCoordinate(1, 0.5f, -0.5f, 0.5f);
	o->setVertexCoordinate(2, -0.5f, -0.5f, 0.5f);

	o->setVertexColor(0, (170)/255.0f, (114)/255.0f, (255)/255.0f);
	o->setVertexColor(1, (114)/255.0f, (255)/255.0f, (131)/255.0f);
	o->setVertexColor(2, (255)/255.0f, (117)/255.0f, (114)/255.0f);

	Vertex vert;
	vert.setCoordinate(0.1f, 0.2f, 0.5f);
	vert.setColor((109)/255.0f, (230)/255.0f, 1.0f);

	o->addVertex(vert);

	o->setType(GL_POINTS);
}

void mainProgram::update() {
	glPointSize(4.0f);
	o->Draw();
}

void mainProgram::shutdown() {

}

