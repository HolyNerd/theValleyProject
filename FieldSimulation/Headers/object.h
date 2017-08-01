#ifndef OBJECT_H
#define OBJECT_H

#include <vertex.h>
#include <GL/glew.h>
#include <shader.h>

class Object {
public:
	Object();
	Object(int amount);
	

	void move(float value[2]);
	void move(float value[2], float width, float height);
	void move(float value[2], bool normalize);
	void move(float, float, bool);

	void addRes(float width, float hegiht);

	void setVertexCoordinate(int index, GLfloat, GLfloat, GLfloat);
	void setVertexColor(int index, GLfloat, GLfloat, GLfloat);
	void addVertex(Vertex);
	void addVertex(int amount);
	void setType(GLenum);
	virtual void Draw();
protected:
	float res[2];

	// Private methods
	virtual void update();
	
	// OpenGL objects
	GLuint buffer;
	GLuint vao;
	Shader shader;

	VertexArray va;
	
	GLenum type;
	bool changed;
};

#endif