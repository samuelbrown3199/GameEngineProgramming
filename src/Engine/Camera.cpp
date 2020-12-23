#include "Camera.h"

#include "Application.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	void Camera::onInitialize()
	{
		up = glm::vec3(0.0f, 1.0f, 0.0f);
	}

	void Camera::onTick()
	{
		view = glm::lookAt(GetEntity()->GetComponent<Transform>()->GetPosition(),
			GetEntity()->GetComponent<Transform>()->GetPosition() + forward, up);
	}
}