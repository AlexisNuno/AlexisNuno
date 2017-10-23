#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader 
{
public:
	Shader();
	~Shader();
	void createShader(std::string path, GLenum type);
	GLuint getHandle();

private:
	
	GLuint _shaderHandle;
	
};