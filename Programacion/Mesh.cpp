#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Mesh.h"

Mesh::Mesh()
{
	_vertexArrayObject = 0;
	_positionsVertexBufferObject = 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;
}
Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &_vertexArrayObject);
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
	_vertexCount = 0;
}


void Mesh::CreateMesh(GLint vertexcount) {
	_vertexCount = vertexcount;
	glGenVertexArrays(1, &_vertexArrayObject);

}
void Mesh::Draw(GLenum primitive) {
	glBindVertexArray(_vertexArrayObject);
	glDrawArrays(primitive, 0, _vertexCount);
	glBindVertexArray(0);


}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex) {


	// positions.size() igual a _vertexCount and positions.size() no sea 0

	if (positions.size() == _vertexCount && positions.size() > 0)
	{
		std::cout << "Coinciden" << std::endl;
		SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(),
			positions.data(), usage, locationIndex, 2);
	}

}
void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex) {
	
	
	if (colors.size()==_vertexCount &&colors.size>0)
	SetAttributeData(_colorsVertexBufferObject, sizeof(glm::vec3) * colors.size(),
		colors.data(), usage, locationIndex, 3);
}

void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components) {;
	if (buffer)
		glDeleteBuffers(1 , &buffer);	glBindVertexArray(buffer);
	
	glGenBuffers(1, &buffer);
	
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	
	glBufferData(GL_ARRAY_BUFFER, size,
		data, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(locationIndex);
	
	glVertexAttribPointer(components, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}	