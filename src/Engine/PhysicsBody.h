#include <iostream>

#include <Bullet/btBulletDynamicsCommon.h>

#include "Component.h"

namespace myengine
{
	class Transform;
	class Collider;

	class PhysicsBody : public Component
	{
		std::shared_ptr<Transform> transform;
		std::shared_ptr<Collider> collider;

	public:

		btScalar mass;
		btVector3 localInertia;
		btRigidBody* rigidBody;

		void onInitialize(float _mass);
		void onTick();
	};
}