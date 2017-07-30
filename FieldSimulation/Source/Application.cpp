#include <Application.h>

Application::Application() : 
	_win_title {"OpenGL Application"},
	_win_width { 640 },
	_win_height { 480 },
	_win_x_position { SDL_WINDOWPOS_CENTERED },
	_win_y_position { SDL_WINDOWPOS_CENTERED }
{
	
}
Application::~Application() {
	SDL_GL_DeleteContext(_gl_context);
	SDL_DestroyWindow(_gl_win);
	SDL_Quit();
}

void Application::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	_gl_win = SDL_CreateWindow (
		_win_title,
		_win_x_position,
		_win_y_position,
		_win_width,
		_win_height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	_gl_context = SDL_GL_CreateContext(_gl_win);

	GLenum status = glewInit();
	if(status != GLEW_OK) {
		throw GLEW_INIT_ERROR();
	}
}

bool Application::applicationClosed() {
	return isClosed;
}

void Application::sdlSwapBuffers() {
	SDL_GL_SwapWindow(_gl_win);
}
void Application::sdlPollEvents() {
	SDL_Event e;

	while(SDL_PollEvent(&e)) {
		if(e.type == SDL_QUIT) {
			isClosed = true;
		}
	}
}

void Application::start() {

}
void Application::update() {

}
void Application::shutdown() {

}
void Application::isResized() {
	
}