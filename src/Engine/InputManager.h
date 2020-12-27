#pragma once
#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <SDL.h>

namespace myengine
{
	class InputManager
	{
	public:
		/**
		*Stores the mouse position in the window.
		*/
		static int mouseX, mouseY;

		InputManager();
		~InputManager();

		/**
		*Returns a boolean if the passed parameter key is down or not.
		*/
		static bool IfKeyDown(SDL_Scancode key);
		/**
		*Returns a boolean if the passed mouse button is down. 0 is left mouse button, 1 is right mouse button.
		*/
		static bool IfMouseButtonDown(int button);
		/**
		*Gets the current mouse position.
		*/
		static void GetMousePosition();
	};
}
#endif

