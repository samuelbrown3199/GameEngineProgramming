#include <GL/glew.h>

#include "Resource.h"

namespace myengine
{
	/**
	*Stores model data.
	*/
	class Model : public Resource
	{
	private:

	public:
		GLuint vaoID;
		size_t drawCount;

		void OnLoad();
	};
}