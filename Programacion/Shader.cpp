#include <fstream>
#include <iostream>
#include <sstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"
#include "InputFile.h"

Shader::Shader()
{
	_shaderHandle = 0;

}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);

}
void Shader::createShader(std::string path, GLenum type)
{
	if (_shaderHandle > 0) {
		glDeleteShader(_shaderHandle);
	}
	InputFile ifile;
	
	ifile.Read(path);
	std::string shaderSource = ifile.GetContents();
	const GLchar *shaderSource_c = (const GLchar*)shaderSource.c_str();
	_shaderHandle = glCreateShader(type);
		glShaderSource(_shaderHandle, 1, &shaderSource_c, nullptr);
		glCompileShader(_shaderHandle);

			GLint vertexShaderCompileSuccess = 0;
			glGetShaderiv(_shaderHandle, GL_COMPILE_STATUS,
				&vertexShaderCompileSuccess);
			if (vertexShaderCompileSuccess == GL_FALSE)
			{
				GLint logLength = 0;
				glGetShaderiv(_shaderHandle, GL_INFO_LOG_LENGTH, &logLength);
				if (logLength > 0)
				{
					std::vector<GLchar> compileLog(logLength);
					glGetShaderInfoLog(_shaderHandle, logLength, &logLength,
						&compileLog[0]);

					for (int i = 0; i < logLength; i++)
					{
						std::cout << compileLog[i];
					}
					std::cout << std::endl;
				}
			std::cout << "Shader Default.vert did not compiled." << std::endl;
		}
}


	GLuint Shader::getHandle(){

	return _shaderHandle;
	};