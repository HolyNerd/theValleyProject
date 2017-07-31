
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <iostream>

#ifndef SHADER_H
#define SHADER_H



class Shader {
public:
	enum status { OK, COMPILATION_ERROR, LINK_ERROR };

	Shader();
	Shader(const unsigned int, const char**, const GLenum*);
	~Shader();

	void bindShader();

	void printLog();
	void printLinkLog();

	const status getStatus() const;
	const status shaderData(const unsigned int, const char**, const GLenum*);

	void deleteShader();

private:
	GLuint _program;

	unsigned int _shaders_amount;
	const char** _shaders_names;
	const GLenum* _shaders_types;

	status _status;

	std::string state;
	GLchar infoLog[512];

	std::string shadersPath = "/home/holynerd/Desktop/theValleyProject/FieldSimulation/Shaders/";
	
	void createShader(const GLenum& type, const char* fName, GLuint&);
	const status createProgram (const unsigned int, const GLenum*, const char**); 

	std::string getShaderSource(const std::string path);

	bool compilationSuccess(GLuint&);
	bool linkSuccess();
};

#endif