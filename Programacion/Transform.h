#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
private:
	glm::mat4 _modelMatrix;
	glm::quat _rotation;
	glm::vec3 _position;
	glm::vec3 _scale;
	
	void updateModelMatrix();

public:

	Transform();
	glm::mat4 GetModelMatrix();
	glm::vec3 GetPosition();
	glm::quat GetRotation();
	glm::vec3 GetScale();

	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);


};
