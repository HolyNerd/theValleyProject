#include <glLibFacilities.h>

namespace glhm {

	std::string getShaderSource(const std::string path) {
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

	GLuint createShader(GLenum& type, const char* fName) {
		GLuint shader = glCreateShader(type);

		std::string shaderStr = getShaderSource(shadersPath + fName);
		const char* shaderSrc = shaderStr.c_str();

		glShaderSource(shader, 1, &shaderSrc, NULL);
		glCompileShader(shader);

		printShaderLog(shader);

		return shader;
	}

	void createProgram (
		unsigned int amount,
		GLenum* types,
		const char* shadersNames[],
		GLuint* program
	) 
	{
		*program = glCreateProgram();

		GLuint* shaders = new GLuint[amount];

		for(int i = 0; i < amount; i++) {
			shaders[i] = createShader(types[i], shadersNames[i]);

			glAttachShader(*program, shaders[i]);
		}

		glLinkProgram(*program);
		printProgramLog(*program);

		for(int i = 0; i < amount; i++)
			glDeleteShader(shaders[i]);
	}

	void printProgramLog(GLuint& program) {
		GLint status;
		GLchar infoLog[512];

		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if(!status) {
			glGetProgramInfoLog(program, 512, nullptr, infoLog);
			std::cout << "Program failed to link: " << infoLog << std::endl;
		}
	}
	void printShaderLog(GLuint& shader) {
		GLint success;
		GLchar infoLog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		
		GLint type;
		glGetShaderiv(shader, GL_SHADER_TYPE, &type);

		if(!success) {
			std::string shaderType;
			switch(type) {
				case GL_VERTEX_SHADER: shaderType = "Vertex "; break;
				case GL_FRAGMENT_SHADER: shaderType = "Fragment "; break;
			}

			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::cout << shaderType << "Shader compilation failed: " << infoLog << std::endl;
		}
	}
	
};