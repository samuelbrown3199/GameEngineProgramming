#include <exception>
#include <memory>
#include <GL/glew.h>

#include "Component.h"

namespace myengine
{
	class Shader;

	class TriangleRenderer : public Component
	{
	private:

		std::shared_ptr<Shader> shader;

	public:
		
		TriangleRenderer();

		GLuint vaoId = 0;
		void onInitialize();
		void onRender();

	};
}