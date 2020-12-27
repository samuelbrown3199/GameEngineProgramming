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
	MeshRenderer component. Renders a mesh.
	*/
	class MeshRenderer : public Component
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
		/**
		*Sets the shader of the mesh renderer.
		*/
		void SetShader(std::shared_ptr<Shader>sha);
		/**
		*Sets the texture of the mesh renderer.
		*/
		void SetTexture(std::shared_ptr <Texture> tex);

	private:
		std::shared_ptr<Shader> shader;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<Model> model;
	};
}