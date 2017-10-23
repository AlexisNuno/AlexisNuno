#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <memory>
#include <vector>
#include "Shader.h"
class ShaderProgram 
{
public:
	ShaderProgram();
	void createProgram();
	void attachShader(std::string path, GLenum type);
	void linkProgram();
	void activate();	
	void deactivate();
	void setAttribute(GLuint locationIndex, std::string name);
	void setUniformf(std::string name, float value);
	void setUniformf(std::string name, float x, float y);
	void setUniformf(std::string name, float x, float y, float z);
	void setUniformf(std::string name, float x, float y, float z, float w);
private:
	GLuint _programHandle;
	std::vector<std::unique_ptr<Shader>> _attachedShaders;

	void deleteAndDetachShaders();
	void deleteProgram();
};