#include "Transform.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

Transform::Transform()
{
	_modelMatrix = glm::mat4();
	_rotation = glm::quat(glm::radians(glm::vec3(0.0f, 0.0f, 0.0f)));
	_position = glm::vec3(0, 0, 0);
	_scale = glm::vec3(1.0, 1.0, 1.0);
}

glm::mat4 Transform::GetModelMatrix() {

	return glm::mat4(_modelMatrix);

}
glm::quat Transform::GetRotation() {

	return glm::quat(_rotation);
}

glm::vec3 Transform::GetPosition()
{
	return glm::vec3(_position);
}

glm::vec3 Transform::GetScale() {
	return glm::vec3(_scale);
}

void Transform::setPosition(float x, float y, float z) {
	_position = glm::vec3(x, y, z);
	updateModelMatrix();
}
void Transform::setRotation(float x, float y, float z) {
	_rotation = glm::vec3(glm::radians(glm::vec3(x, y, z)));
	updateModelMatrix();
}
void Transform::setScale(float x, float y, float z) {
	_scale = glm::vec3(x, y, z);
	updateModelMatrix();
}

void Transform::updateModelMatrix() {

	_modelMatrix = glm::mat4_cast(_rotation);

	_modelMatrix[0] = _modelMatrix[0] * _scale[0];
	_modelMatrix[1] = _modelMatrix[1] * _scale[1];
	_modelMatrix[2] = _modelMatrix[2] * _scale[2];

	_modelMatrix[3][0] = _position[0];
	_modelMatrix[3][1] = _position[1];
	_modelMatrix[3][2] = _position[2];

}

