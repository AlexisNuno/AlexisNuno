#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "ShaderProgram.h"
#include <memory>

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram()
{
	deleteProgram();
}
void ShaderProgram::createProgram()
{
	_programHandle = glCreateProgram();
}
void ShaderProgram::attachShader(std::string name, GLenum type)
{

	std::unique_ptr<Shader> shader(new Shader);
	shader->createShader(name, type);
	_attachedShaders.push_back(std::move(shader));
}
void ShaderProgram::linkProgram()
{
	for (int i = 0; i < _attachedShaders.size(); i++) {
		glAttachShader(_programHandle, _attachedShaders[i]->getHandle());
	}
	glLinkProgram(_programHandle);

	deleteAndDetachShaders();
	
}
	
	void ShaderProgram::deleteAndDetachShaders()
	{
		for (int i = 0; i < _attachedShaders.size(); i++) {
			glDetachShader(_programHandle, _attachedShaders[i]->getHandle());
		}
		_attachedShaders.clear();
	}
	void ShaderProgram::activate()
	{
		glUseProgram(_programHandle);
	}
	void ShaderProgram::deactivate()
	{

		glUseProgram(0);
	}
	void ShaderProgram::setAttribute(GLuint locationIndex, std::string name)
	{
		glBindAttribLocation(_programHandle, locationIndex, name.c_str());
	}
	void ShaderProgram::deleteProgram()
	{
		deleteAndDetachShaders();
		glDeleteProgram(_programHandle);
	}
	
	
