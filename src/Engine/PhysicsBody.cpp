#include "PhysicsBody.h"

#include "Entity.h"

namespace myengine
{
	void PhysicsBody::onInitialize()
	{
		transform = GetEntity()->GetComponent<Transform>();
	}

	void PhysicsBody::onTick()
	{
		//calculate new position

		glm::vec3 newPos(transform->position.x + velX, transform->position.y + velY, transform->position.z + velZ);
		transform->SetPosition(newPos);
	}
}