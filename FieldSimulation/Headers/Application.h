#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

class Application {
public:
	Application();
	~Application();

	bool applicationClosed();
	void sdlSwapBuffers();
	void sdlPollEvents();

	virtual void init();
	virtual void start();
	virtual void update();
	virtual void shutdown();
protected:
	bool isClosed;

	const char* _win_title;
	int _win_width;
	int _win_height;
	int _win_x_position;
	int _win_y_position;

	SDL_Window* _gl_win;
	SDL_GLContext _gl_context;
private:
};

#define MAIN(CLASS) CLASS c; int main() {c.init(); c.start(); while(!c.applicationClosed()) {c.update(); c.sdlSwapBuffers(); c.sdlPollEvents(); } c.shutdown();}

class GLEW_INIT_ERROR { };

#endif

