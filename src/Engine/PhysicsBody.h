#include <iostream>

#include "Component.h"

#include "Physics.h"

namespace myengine
{
	class Transform;

	class PhysicsBody : public Component
	{
		std::shared_ptr<Transform> transform;
		glm::dvec3 bodyVelocity = glm::dvec3(0, 0, 0);
		glm::dvec3 angularVelocity = glm::dvec3(0, 0, 0);
		float mass = 20, dragCoeffient = 1.05f, area = 1.0f;

	public:
		void onInitialize();
		void onTick();
	};
}