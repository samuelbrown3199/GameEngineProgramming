#include "Component.h"

#include "Transform.h"
#include "Physics.h"

namespace myengine
{
	class PhysicsBody : public Component
	{
		std::shared_ptr<Transform> transform;
		double velX, velY, velZ;

		void onInitialize();
		void onTick();
	};
}