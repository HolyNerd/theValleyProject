#include <mainProgram.h>


void mainProgram::init() {

	_win_width = 500;
	_win_height = 500;

	Application::init();
}

void mainProgram::start() {
	GLfloat color[] = { (201)/255.0f, (237)/255.0f, (227)/255.0f };
	glClearBufferfv(GL_COLOR, 0, color);

	grid = new Grid(50, 500, 500);
	charge = new Charge[5];;
	charge[0].move(0.5f, 0.5f, false);
	charge[1].move(-0.1, -0.3, false);
	charge[1].setCharge(Charge::NEGATIVE);
	
	
}

void mainProgram::update() {
	grid->Draw();
	for(int i = 0; i < 2; i++)
		charge[i].Draw();

}

void mainProgram::shutdown() {

}

