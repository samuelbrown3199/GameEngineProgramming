#include "glm/glm.hpp"
#include "glm/ext.hpp"

namespace myengine
{
	/**
	*Stores and generates information based on the screen.
	*/
	class Screen
	{
	private:
		/**
		*Stores the current screen size.
		*/
		int screenWidth = 900, screenHeight = 900;

	public:
		/**
		*Sets the screen height to the passed value.
		*/
		void SetScreenHeight(int height);
		/**
		*Sets the screen width to the passed value.
		*/
		void SetScreenWidth(int width);
		/**
		*Returns the screen height.
		*/
		int GetScreenHeight();
		/**
		*Returns the screen width.
		*/
		int GetScreenWidth();
		/**
		*Generates a perspective matrix based on the screen information.
		*/
		glm::mat4 GetPerspective();
		/**
		*Generates an orthographic matrix based on the screen information.
		*/
		glm::mat4 GetOrthographic();
	};
}