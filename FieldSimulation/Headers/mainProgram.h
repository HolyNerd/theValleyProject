#include <application.h>
#include <shader.h>
#include <object.h>
#include <charge.h>
#include <grid.h>

class mainProgram : public Application {
public:
	void init();
	void start();
	void update();
	void shutdown();

private:
	Charge* charge;
	Grid* grid;
};


MAIN(mainProgram)