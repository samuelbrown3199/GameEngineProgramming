#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Resource.h"

namespace myengine
{
	class Texture : public Resource
	{
	private:
		GLuint textureID;

	public:
		void LoadTexture(std::string path);
	};
}