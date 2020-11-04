#include<glm/glm.hpp>
#include <glm/ext.hpp>

#include "Component.h"

namespace myengine
{
	class Transform : public Component
	{
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

	public:

		void onInitialize();

		void SetPosition(glm::vec3 pos);
		void SetRotation(glm::vec3 rot);
		glm::mat4 GetModelMatrix();
	};
}