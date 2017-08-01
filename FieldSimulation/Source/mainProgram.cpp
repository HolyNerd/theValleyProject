#include <mainProgram.h>
#include <thread>
#include <parser.h>

mainProgram::mainProgram() : grid(50, 640, 480) {
	
}

void mainProgram::init() {
}

void mainProgram::start() {

}

void mainProgram::update() {
	GLfloat color[] = { (245)/255.0f, (244)/255.0f, (255)/255.0f };
	glClearBufferfv(GL_COLOR, 0, color);

	static std::string result = "";
	if(result != "q")
		result = parsing(&canvas);



	grid.Draw();
	canvas.Draw();


}

void mainProgram::shutdown() {

}

