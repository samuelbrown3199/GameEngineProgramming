#include <exception>
#include <memory>
#include <GL/glew.h>

#include "Component.h"

namespace myengine
{
	class Shader;
	class Texture;
	/**
	*Stores a renderable triangle.
	*/
	class TriangleRenderer : public Component
	{
	private:
		/**
		*The current shader of the triangle sdlRenderer.
		*/
		std::shared_ptr<Shader> shader;
		/**
		*The current texture of the triangle sdlRenderer.
		*/
		std::shared_ptr<Texture> texture;

	public:
		
		TriangleRenderer();

		GLuint vaoId = 0;
		/**
		*Initializes the triangle.
		*/
		void onInitialize();
		/**
		*Renders the triangle.
		*/
		void onRender();

	};
}