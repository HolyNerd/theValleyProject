#include <object.h>

Object::Object(int amount) : va(amount), changed{ true }
{

	GLenum st[2] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
	const char* sn[2] = { "vertShader.glsl", "fragShader.glsl" };

	shader.shaderData(2, sn, st);
}

void Object::setVertexCoordinate(int index, GLfloat x, GLfloat y, GLfloat z) {
	va[index].setCoordinate(x, y, z);
	changed = true;
}

void Object::setVertexColor(int index, GLfloat r, GLfloat g, GLfloat b) {
	va[index].setColor(r, g, b);
	changed = true;	
}

void Object::addVertex(Vertex& vert) {
	va.add(vert.getCoordinate(), vert.getColor());
}

void Object::setType(GLenum t) {
	type = t;
}

void Object::update() {
	if(buffer != 0)
		glDeleteBuffers(1, &buffer);
	if(vao != 0)
		glDeleteVertexArrays(1, &vao);
	
	glGenBuffers(1, &buffer);
	glGenVertexArrays(1, &vao);
	
	GLfloat* data = va.getData();

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * va.getAmount() * 6, data, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)0);
	GLsizeiptr coffset = sizeof(GLfloat)*3;
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 6, (void*)coffset);
	std::cout << &data[3] << std::endl;
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	changed = false;
}

void Object::Draw() {
	if(changed)
		update();

	glBindVertexArray(vao);
	shader.bindShader();
	glDrawArrays(type, 0, va.getAmount());
}