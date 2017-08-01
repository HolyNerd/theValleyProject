#include <vertex.h>


// Constructors
Vertex::Vertex() 
	: coordinate{ 0.0f, 0.0f, 0.0f }, color{ 1.0f, 1.0f, 1.0f }
{

}

Vertex::Vertex(GLfloat x, GLfloat y, GLfloat z) 
	: coordinate{ 0.0f, 0.0f, 0.0f }, color{ 1.0f, 1.0f, 1.0f }
{
	setCoordinate(x, y, z);
}

Vertex::Vertex(GLfloat* newCoordinate) 
	: coordinate{ 0.0f, 0.0f, 0.0f }, color{ 1.0f, 1.0f, 1.0f }
{
	for(int i = 0; i < 3; i++)
		coordinate[i] = newCoordinate[i];
}

Vertex::Vertex(GLfloat* newCoordinate, GLfloat* newColor) 
	: coordinate{ 0.0f, 0.0f, 0.0f }, color{ 1.0f, 1.0f, 1.0f }
{	
	for(int i = 0; i < 3; i++)
		coordinate[i] = newCoordinate[i];
		
	for(int i = 0; i < 3; i++)
		color[i] = newColor[i];
}

Vertex::Vertex(const Vertex& rhs) 
	: coordinate{ 0.0f, 0.0f, 0.0f }, color{ 1.0f, 1.0f, 1.0f }
{
	for(int i = 0; i < 3; i++)
		coordinate[i] = rhs.coordinate[i];
		
	for(int i = 0; i < 3; i++)
		color[i] = rhs.color[i];
}

Vertex::~Vertex() { }

// Get-Set methods

GLfloat* Vertex::getCoordinate(){
	return coordinate;
}
GLfloat* Vertex::getColor() {
	return color;
}

void Vertex::setCoordinate(GLfloat c[3]) {
	for(int i = 0; i < 3; i++)
		coordinate[i] = c[i];
}
void Vertex::setColor(GLfloat c[3]) {
	for(int i = 0; i < 3; i++)
		color[i] = c[i];
}
void Vertex::setCoordinate(GLfloat x, GLfloat y, GLfloat z) {
	coordinate[0] = x;
	coordinate[1] = y;
	coordinate[2] = z;
}
void Vertex::setColor(GLfloat r, GLfloat g, GLfloat b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

VertexArray::VertexArray() 
	: amount{ 1 }
{
	array = new Vertex[amount];
}

VertexArray::VertexArray(int newAmount) 
	: amount{ newAmount }
{
	array = new Vertex[amount];
}


Vertex& VertexArray::operator[](int index) {
	return array[index];
}

void VertexArray::add(GLfloat* coord, GLfloat* color) {
	Vertex* backup = new Vertex[amount];

	for(int i = 0; i < amount; i++) {
		backup[i] = array[i];
	}

	delete[] array;
	
	amount++;

	array = new Vertex[amount];

	for(int i = 0; i < amount-1; i++) {
		array[i] = backup[i];
	}

	array[amount - 1].setCoordinate(coord);
	array[amount - 1].setColor(color);
}

void VertexArray::add(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b) {
	Vertex* backup = new Vertex[amount];

	for(int i = 0; i < amount; i++) {
		backup[i] = array[i];
	}

	delete[] array;

	amount++;

	array = new Vertex[amount];

	for(int i = 0; i < amount-1; i++) {
		array[i] = backup[i];
	}

	array[amount - 1].setCoordinate(x, y, z);
	array[amount - 1].setColor(r, g, b);
}

void VertexArray::add(int count) { 
	Vertex* backup = new Vertex[amount];

	for(int i = 0; i < amount; i++) {
		backup[i] = array[i];
	}

	delete[] array;

	array = new Vertex[amount + count];

	for(int i = 0; i < amount; i++) {
		array[i] = backup[i];
	}

	amount += count;
}

GLfloat* VertexArray::getData() {
	GLfloat* data = new GLfloat[6 * amount];
	int dataIterator = 0;

	for(int i = 0; i < amount; i++) {
		GLfloat* tempCoord = array[i].getCoordinate();
		GLfloat* tempColor = array[i].getColor();

		for(int j = 0; j < 3; j++) {
			data[dataIterator] = tempCoord[j];
			data[dataIterator+3] = tempColor[j];

			dataIterator++;
		}
		dataIterator += 3;
	}

	return data;
}

int VertexArray::getAmount() const {
	return amount;
}

void VertexArray::move(float value[2]) {
	for(int i = 0; i < amount; i++) {
		GLfloat* vertCoord = array[i].getCoordinate();
		vertCoord[0] += value[0];
		vertCoord[1] += value[1];
	}
}