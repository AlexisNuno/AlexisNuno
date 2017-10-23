#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
class Mesh {
private:
	void SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void* data, GLenum usage, GLuint locationIndex, const GLint components);
	GLuint _vertexArrayObject;
	GLuint _positionsVertexBufferObject;
	GLuint _colorsVertexBufferObject;
	GLuint _vertexCount;
public:
	Mesh();
	~Mesh();
	void CreateMesh(GLint vertexCount);
	void Draw(GLenum primitive);
	void SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locatonIndex);
	void SetPositionAttribute(std::vector<glm::vec3>positions, GLenum usage, GLuint locatonIndex);
	void SetColorAttribute(std::vector <glm::vec3> positions, GLenum usage, GLuint locatonIndex);
	void SetColorAttribute(std::vector <glm::vec4> positions, GLenum usage, GLuint locatonIndex);
};