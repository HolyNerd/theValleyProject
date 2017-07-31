#include <application.h>
#include <shader.h>

class FieldSimulation : public Application {
public:
	void init();
	void start();
	void update();
	void shutdown();

protected:	

private:
	Shader shader;
	GLuint program;
};


MAIN(FieldSimulation)