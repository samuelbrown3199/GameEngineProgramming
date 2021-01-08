#include "Collider.h"

#include "Entity.h"
#include "Application.h"
#include "PhysicsWorld.h"

namespace myengine
{
	void Collider::onInitialize(ColliderShape _shape)
	{
		colliderTransform = GetEntity()->GetComponent<Transform>();

		colliderShape = _shape;

		switch (colliderShape)
		{
		case box:
			shape = new btBoxShape(btVector3(colliderTransform->scale.x, colliderTransform->scale.y, colliderTransform->scale.z));
			break;
		case sphere:
			shape = new btSphereShape(colliderTransform->scale.x);
			break;
		}

		GetApplication()->GetPhysicsWorld()->AddCollider(shape);
	}
}