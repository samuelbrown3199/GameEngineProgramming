#include "PhysicsBody.h"

#include "Entity.h"
#include "Transform.h"
#include "Collider.h"
#include "Application.h"
#include "PhysicsWorld.h"

namespace myengine
{
	void PhysicsBody::onInitialize(btScalar _mass)
	{
		transform = GetEntity()->GetComponent<Transform>();
		collider = GetEntity()->GetComponent<Collider>();

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
		rbInfo.m_linearDamping = .2f;
		rbInfo.m_angularDamping = .2f;
		rbInfo.m_restitution = 0.35;

		rigidBody = new btRigidBody(rbInfo);
		rigidBody->setFriction(.5f);
		rigidBody->setRollingFriction(.5f);

		GetApplication()->GetPhysicsWorld()->AddRigidbody(rigidBody);
	}

	void PhysicsBody::onTick()
	{
		if (rigidBody && rigidBody->getMotionState())
		{
			rigidBody->getMotionState()->getWorldTransform(bodyTransform);
		}
	}
}