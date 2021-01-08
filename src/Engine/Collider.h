#pragma once
#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Component.h"
#include "Transform.h"

#include <Bullet/btBulletDynamicsCommon.h>

namespace myengine
{
	class Collider : public Component
	{
		std::shared_ptr<Transform> colliderTransform;

	public:
		btCollisionShape* shape;
		void onInitialize();
	};
}

#endif