#pragma once
#include <SDL.h>

#include <vector>

namespace myengine
{
	class InputManager
	{
	public:

		static int mouseX, mouseY;

		InputManager();
		~InputManager();

		static bool IfKeyDown(SDL_Scancode key);
		static bool IfMouseButtonDown(int button);
		static void GetMousePosition();

	private:
	};
}
