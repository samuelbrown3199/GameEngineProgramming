#include <GL/glew.h>

#include "Resource.h"

namespace myengine
{
	class Model : public Resource
	{
	private:

	public:
		GLuint vaoID;
		size_t drawCount;

		void OnLoad();
	};
}