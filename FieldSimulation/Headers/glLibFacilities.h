
#include <string>
#include <GL/glew.h>

#include <iostream>
#include <fstream>

namespace glhm {

	std::string getShaderSource(const std::string path);

	GLuint createShader(GLenum& type, const char*  fName);

	void createProgram (
		unsigned int amount,
		GLenum* types,
		const char* shadersNames[],
		GLuint* program
	);

	void printProgramLog(GLuint& program);
	void printShaderLog(GLuint& shader);

	static const std::string shadersPath = "/home/holynerd/Desktop/theValleyProject/FieldSimulation/Shaders/";

};