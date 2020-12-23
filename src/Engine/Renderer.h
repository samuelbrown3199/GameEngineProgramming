#include <exception>
#include <memory>
#include <string>
#include <GL/glew.h>

#include "Component.h"

namespace myengine
{
	class Shader;
	class Texture;
	class Model;
	
	/**
	Renderer component. Renders a mesh.
	*/
	class Renderer : public Component
	{
		/**
		*Renders the mesh with the texture.
		*/
		void onRender();
	public:
		/**
		*Loads the model at the path and sets it as the model.
		*/
		void SetModel(std::string modelPath);

		void SetShader(std::shared_ptr<Shader>sha);

		void SetTexture(std::shared_ptr <Texture> tex);

	private:
		std::shared_ptr<Shader> shader;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<Model> model;
	};
}