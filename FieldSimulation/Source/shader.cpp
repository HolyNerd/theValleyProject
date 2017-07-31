#include <shader.h>

// CONSTRUCTORS
Shader::Shader() {
	_status = OK;
}

Shader::Shader (
	const unsigned int shadersAmount, 
	const char** shadersNames, 
	const GLenum* shadersTypes) 
: _shaders_amount {shadersAmount}
{ 

	_status = status::OK;

	_shaders_names = shadersNames;
	_shaders_types = shadersTypes;

	_status = createProgram (
		_shaders_amount, 
		_shaders_types, 
		_shaders_names
	);	
}

Shader::~Shader() { }

void Shader::deleteShader() {
	glDeleteProgram(_program);
}

const Shader::status Shader::getStatus() const {
	return _status;
}

void Shader::bindShader() {
	glUseProgram(_program);
}

const Shader::status Shader::shaderData (
	const unsigned int shadersAmount, 
	const char** shadersNames, 
	const GLenum shadersTypes[]) 
{
	_shaders_amount = shadersAmount;
	_shaders_names = shadersNames;
	_shaders_types = shadersTypes;

	_status = createProgram (
		_shaders_amount, 
		_shaders_types, 
		_shaders_names
	);

	return _status;
}

std::string Shader::getShaderSource(const std::string path) {
	std::string content;
	std::ifstream fs(path, std::ios::in);

	if(!fs.is_open()) {
		std::cerr << "Could not read file " << path << std::endl;
		return "";
	}

	std::string line = "";
	while(!fs.eof()) {
		std::getline(fs, line);
		content.append(line + "\n");
	}

	fs.close();
	return content;
}
void Shader::createShader(const GLenum& type, const char* fName, GLuint& shader) {
	shader = glCreateShader(type);

	std::string shaderStr = getShaderSource(shadersPath + fName);
	const char* shaderSrc = shaderStr.c_str();

	glShaderSource(shader, 1, &shaderSrc, NULL);
	glCompileShader(shader);
}

const Shader::status Shader::createProgram (
	const unsigned int amount,
	const GLenum* types,
	const char** shadersNames
) 
{
	_program = glCreateProgram();

	GLuint* shaders = new GLuint[amount];

	for(int i = 0; i < amount; i++) {
		createShader(types[i], shadersNames[i], shaders[i]);

		if(!compilationSuccess(shaders[i])) {
			state = "COMPILATION ERROR IN :";
			state += shadersNames[i];
			glGetShaderInfoLog(shaders[i], 512, nullptr, infoLog);

			for(int j = 0; j <= i; j++)
				glDeleteShader(shaders[j]);

			return status::COMPILATION_ERROR;
		}

		glAttachShader(_program, shaders[i]);
	}

	glLinkProgram(_program);

	for(int i = 0; i < amount; i++) {
		glDetachShader(_program, shaders[i]);
		glDeleteShader(shaders[i]);
	}
	if(!linkSuccess()) {
		state = "LINK ERROR ";
		glGetProgramInfoLog(_program, 512, nullptr, infoLog);

		return status::LINK_ERROR;
	}
}

void Shader::printLog() {
	std::cout << state << " : " << infoLog << std::endl;
}

bool Shader::compilationSuccess(GLuint& shader) {
	GLint success;

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if(success) 
		return true;
	return false;
}
bool Shader::linkSuccess() {
	GLint success;

	glGetProgramiv(_program, GL_LINK_STATUS, &success);

	if(success) 
		return true;
	return false;
}