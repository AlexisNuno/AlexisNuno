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

void setPosition
