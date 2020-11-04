#include "Transform.h"
using namespace myengine;

void Transform::onInitialize()
{
	scale = glm::vec3(1, 1, 1);
}

void Transform::SetPosition(glm::vec3 pos)
{
	position = pos;
}

void Transform::SetRotation(glm::vec3 rot)
{
	rotation = rot;
}

glm::mat4 Transform::GetModelMatrix()
{
	glm::mat4 rtn(1.0f);

	rtn = glm::translate(rtn, position);
	rtn = glm::rotate(rtn, glm::radians(rotation.x), glm::vec3(1, 0, 0));
	rtn = glm::rotate(rtn, glm::radians(rotation.y), glm::vec3(0, 1, 0));
	rtn = glm::rotate(rtn, glm::radians(rotation.z), glm::vec3(0, 0, 1));
	rtn = glm::scale(rtn, scale);

	return rtn;
}