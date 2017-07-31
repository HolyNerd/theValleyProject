#include <application.h>
#include <shader.h>
#include <object.h>

class mainProgram : public Application {
public:
	void init();
	void start();
	void update();
	void shutdown();

private:
	Object* o;
};


MAIN(mainProgram)