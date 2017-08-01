#include <application.h>
#include <shader.h>
#include <object.h>
#include <charge.h>
#include <grid.h>
#include <canvas.h>

class mainProgram : public Application {
public:
	mainProgram();

	void init();
	void start();
	void update();
	void shutdown();

private:
	Canvas canvas;
	Grid grid;
};


MAIN(mainProgram)