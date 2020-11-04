#include <GL/glew.h>


#include "Resource.h"

namespace myengine
{
	class Texture : public Resource
	{
	private:

	public:
		GLuint textureID;

		void OnLoad();
	};
}