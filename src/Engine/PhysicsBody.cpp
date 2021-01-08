#include "PhysicsBody.h"

#include "Entity.h"
#include "Transform.h"
#include "Collider.h"
#include "Application.h"
#include "PhysicsWorld.h"

namespace myengine
{
	void PhysicsBody::onInitialize(float _mass)
	{
		transform = GetEntity()->GetComponent<Transform>();
		collider = GetEntity()->GetComponent<Collider>();

		btTransform bodyTransform;
		bodyTransform.setIdentity();
		bodyTransform.setOrigin(btVector3(transform->position.x, transform->position.y, transform->position.z));
		bodyTransform.setRotation(btQuaternion(transform->rotation.x, transform->rotation.y, transform->rotation.z));

		mass = _mass;

		btVector3 localInertia(0,0,0);
		bool isDynamic = (mass != 0.f);
		if (isDynamic)
		{
			collider->shape->calculateLocalInertia(mass, localInertia);
		}
		btDefaultMotionState* motionState = new btDefaultMotionState(bodyTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, collider->shape, localInertia);
		rigidBody = new btRigidBody(rbInfo);

		GetApplication()->GetPhysicsWorld()->AddRigidbody(rigidBody);
	}

	void PhysicsBody::onTick()
	{
		btTransform trans;
		if (rigidBody && rigidBody->getMotionState())
		{
			rigidBody->getMotionState()->getWorldTransform(trans);
			transform->SetPosition(glm::vec3(trans.getOrigin().getX(), trans.getOrigin().getY(), trans.getOrigin().getZ()));
			transform->SetRotation(glm::vec3(trans.getRotation().getX(), trans.getRotation().getY(), trans.getRotation().getZ()));
		}
	}
}