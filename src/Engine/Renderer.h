#include <exception>
#include <memory>
#include <GL/glew.h>

#include "Component.h"

namespace myengine
{
	class Shader;

	class Renderer : public Component
	{
		void onRender();

	private:
		std::shared_ptr<Shader> shader;

	};
}