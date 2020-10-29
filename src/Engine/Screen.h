#include "glm/glm.hpp"
#include "glm/ext.hpp"

namespace myengine
{
	class Screen
	{
	private:

		int screenWidth = 650, screenHeight = 650;

	public:

		void SetScreenHeight(int height);
		void SetScreenWidth(int width);

		int GetScreenHeight();
		int GetScreenWidth();

		glm::mat4 GetPerspective();
	};
}