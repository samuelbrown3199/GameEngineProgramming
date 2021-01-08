#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Component.h"
#include "Transform.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace myengine
{
	/**
	*Responsible for adding a collider to an object. Objects also require a physics to be added to the object for physics to work.
	*/
	class Collider : public Component
	{
		std::shared_ptr<Transform> colliderTransform;

	public:
		enum ColliderShape
		{
			box,
			sphere
		};
		/**
		*Used to detemine the shape of the collider.
		*/
		ColliderShape colliderShape;
		/**
		*Stores a collider shape pointer.
		*/
		btCollisionShape* shape;
		void onInitialize(ColliderShape _shape);
	};
}

#endif