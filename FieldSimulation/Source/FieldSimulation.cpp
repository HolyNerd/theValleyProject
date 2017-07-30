#include <FieldSimulation.h>

void FieldSimulation::init() {
	_win_width = 700;
	_win_height = 700;

	Application::init();
}

void FieldSimulation::start() {
	GLenum shaderTypes[2] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER};
	const char* shadersNames[2] = {"vertShader.glsl", "fragShader.glsl"};

	compileProgram(2, shaderTypes, shadersNames, &program);
}

void FieldSimulation::update() {
	static const GLfloat bhColor[] = { 0.2f, 0.4f, 0.7f, 1.0f };
	glClearBufferfv(GL_COLOR, 0, bhColor);

	glPointSize(10.0f);

	glUseProgram(program);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void FieldSimulation::shutdown() {
	glDeleteProgram(program);
}

