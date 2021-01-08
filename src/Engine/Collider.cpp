#include "Collider.h"

#include "Entity.h"
#include "Application.h"
#include "PhysicsWorld.h"

namespace myengine
{
	void Collider::onInitialize()
	{
		colliderTransform = GetEntity()->GetComponent<Transform>();
		shape = new btBoxShape(btVector3(colliderTransform->scale.x, colliderTransform->scale.y, colliderTransform->scale.z));

		GetApplication()->GetPhysicsWorld()->AddCollider(shape);
	}
}