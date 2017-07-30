#include <Application.h>

#include <fstream>
#include <string>

class FieldSimulation : public Application {
public:
	void init();
	void start();
	void update();
	void shutdown();

protected:
	std::string readFile(const char* filePath) {
		std::string content;
		std::ifstream fs(filePath, std::ios::in);

		if(!fs.is_open()) {
			std::cerr << "Could not read file " << filePath << std::endl;
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
	GLuint compileShader(GLenum type, const char* path) {
		GLuint shader = glCreateShader(type);

		std::string shaderStr = readFile(path);
		const char* shaderSrc = shaderStr.c_str();

		glShaderSource(shader, 1, &shaderSrc, NULL);
		glCompileShader(shaderSrc);

		return shader;
	}

private:
	
};