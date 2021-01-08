#pragma once
#ifndef PHYSICSWORLD_H_
#define PHYSICSWORLD_H_

#include <memory>

#include <Bullet/btBulletDynamicsCommon.h>

namespace myengine
{
	/**
	*Stores various options regarding the bullet physics.
	*/
	class PhysicsWorld
	{
	public:
		btDefaultCollisionConfiguration* collisionConfiguration;
		btCollisionDispatcher* dispatcher;
		btBroadphaseInterface* overlappingPairCache;
		btSequentialImpulseConstraintSolver* solver;
		btDiscreteDynamicsWorld* dynamicWorld;

		btAlignedObjectArray<btCollisionShape*> collisionShapes;

		/**
		*Creates a physics world object.
		*/
		static std::shared_ptr<PhysicsWorld> CreatePhysicsWorld();
		/**
		*Cleans up the physics world memory.
		*/
		void CleanupPhysicsWorld();
		/**
		*Adds a collider to the list of all colliders.
		*/
		void AddCollider(btCollisionShape* shape);
		/**
		*Adds a rigidbody to the physics world.
		*/
		void AddRigidbody(btRigidBody* body);
	};
}

#endif