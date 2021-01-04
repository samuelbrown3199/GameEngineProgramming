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

		bodyVelocity.y = Physics::FreeFallVelocityWithDrag(mass, 1.225, dragCoeffient, area);
		std::cout << "Vel Y is " << bodyVelocity.y << std::endl;

		glm::vec3 newPos(transform->position.x + bodyVelocity.x, transform->position.y + bodyVelocity.y, transform->position.z + bodyVelocity.z);
		glm::vec3 newRot(transform->rotation.x + angularVelocity.x, transform->rotation.y + angularVelocity.y, transform->rotation.z + angularVelocity.z);
		transform->SetPosition(newPos);
		transform->SetRotation(newRot);
	}
}