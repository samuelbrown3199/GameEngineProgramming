#include "PhysicsBody.h"

#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	void PhysicsBody::onInitialize()
	{
		transform = GetEntity()->GetComponent<Transform>();
	}

	void PhysicsBody::onTick()
	{
		//calculate new position

		velY = Physics::FreeFallVelocityWithDrag(20, 1.225, 1.05, 1);
		std::cout << "Vel Y is " << velY << std::endl;

		glm::vec3 newPos(transform->position.x + velX, transform->position.y + velY, transform->position.z + velZ);
		transform->SetPosition(newPos);
	}
}