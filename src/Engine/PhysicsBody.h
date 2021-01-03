#include <iostream>

#include "Component.h"

#include "Physics.h"

namespace myengine
{
	class Transform;

	class PhysicsBody : public Component
	{
		std::shared_ptr<Transform> transform;
		double velX = 0, velY = 0, velZ = 0;

	public:
		void onInitialize();
		void onTick();
	};
}