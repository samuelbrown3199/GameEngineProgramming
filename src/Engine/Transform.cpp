#include "Transform.h"
#include "PhysicsBody.h"
#include "Entity.h"

namespace myengine
{
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

	void Transform::SetScale(glm::vec3 sca)
	{
		scale = sca;
	}

	glm::vec3 Transform::GetPosition()
	{
		return position;
	}

	glm::vec3 Transform::GetRotation()
	{
		return rotation;
	}

	glm::vec3 Transform::GetScale()
	{
		return scale;
	}

	glm::mat4 Transform::GetModelMatrix()
	{
		if (!checkForPBody)
		{
			pBody = GetEntity()->GetComponent<PhysicsBody>();
			checkForPBody = true;
		}
		if (!pBody)
		{
			glm::mat4 rtn(1.0f);

			rtn = glm::translate(rtn, position);
			rtn = glm::rotate(rtn, glm::radians(rotation.x), glm::vec3(1, 0, 0));
			rtn = glm::rotate(rtn, glm::radians(rotation.y), glm::vec3(0, 1, 0));
			rtn = glm::rotate(rtn, glm::radians(rotation.z), glm::vec3(0, 0, 1));
			rtn = glm::scale(rtn, scale);

			return rtn;
		}
		else
		{
			btScalar matrix[16];
			pBody->bodyTransform.getOpenGLMatrix(matrix);

			glm::mat4 rtn = glm::make_mat4(matrix);
			rtn = glm::scale(rtn, scale);
			return rtn;
		}
	}
}