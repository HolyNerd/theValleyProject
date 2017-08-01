#ifndef VERTEX_H
#define VERTEX_H

#include <GL/glew.h>
#include <iostream>

class Vertex {
public:
	Vertex();
	Vertex(GLfloat, GLfloat, GLfloat);
	Vertex(GLfloat* newCoordinate);
	Vertex(GLfloat* newCoordinate, GLfloat* newColor);
	Vertex(const Vertex& rhs);
	~Vertex();

	GLfloat* getCoordinate();
	GLfloat* getColor();

	void setCoordinate(GLfloat, GLfloat, GLfloat);
	void setColor(GLfloat, GLfloat, GLfloat);

	void setCoordinate(GLfloat c[3]);
	void setColor(GLfloat c[3]);

private:
	GLfloat coordinate[3];
	GLfloat color[3];
};

class VertexArray {
public:
	VertexArray(int newAmount);
	
	GLfloat* getData();
	int getAmount() const;
	
	void add(GLfloat* coord, GLfloat* color);
	void add(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void add(int count);

	void move(float value[2]);

	Vertex& operator[](int index);

private:
	Vertex* array;
	int amount;
};

#endif