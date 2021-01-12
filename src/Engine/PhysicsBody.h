#include <iostream>

#include <Bullet/btBulletDynamicsCommon.h>

#include "Component.h"

namespace myengine
{
	class Transform;
	class Collider;

	/**
	*Responsible to creating and adding a rigidbody to the bullet physics world simulation. The entity must have a collider added before adding the physics body component.
	*/
	class PhysicsBody : public Component
	{
		std::shared_ptr<Transform> transform;
		std::shared_ptr<Collider> collider;

	public:
		/**
		*Stores the rigidbody transform within the physics simulation.
		*/
		btTransform bodyTransform;
		/**
		*Stores the rigidbody mass.
		*/
		btScalar mass;
		/**
		*Stores a pointer to the rigidbody.
		*/
		btRigidBody* rigidBody;

		void onInitialize(btScalar _mass);
		void onTick();
	};
}