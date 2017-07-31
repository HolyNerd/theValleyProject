#ifndef OBJECT_H
#define OBJECT_H

#include <vertex.h>
#include <GL/glew.h>
#include <shader.h>

class Object {
public:
	Object(int amount);
	
	void setVertexCoordinate(int index, GLfloat, GLfloat, GLfloat);
	void setVertexColor(int index, GLfloat, GLfloat, GLfloat);
	void addVertex(Vertex&);
	void setType(GLenum);
	void Draw();
private:
	void update();

	GLuint buffer;
	GLuint vao;
	Shader shader;

	VertexArray va;

	GLenum type;

	bool changed;
};

#endif