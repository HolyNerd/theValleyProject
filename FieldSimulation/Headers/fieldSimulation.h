#include <application.h>

class FieldSimulation : public Application {
public:
	void init();
	void start();
	void update();
	void shutdown();

protected:	

private:
	GLuint program;
};


MAIN(FieldSimulation)