#pragma once
#ifndef UICOMPONENT_H_
#define UICOMPONENT_H_

#include<SDL.h>

namespace myengine
{
	/**
	*Ui base component for UI elements to inherit from.
	*/
	class UiComponent
	{
	public:
		/**
		*Stores the rectangle the UI element uses.
		*/
		SDL_Rect rect;
		/**
		*Checks if the mouse is currently hovering over the ui element.
		*/
		bool CheckForMouseHover();
		/**
		*Checks if the ui element has been clicked.
		*/
		bool HasClicked();
		/**
		*Renders the UI element. Child classes have to write their own implementation of this function.
		*/
		virtual void RenderUiElement();
	};
}

#endif // !UICOMPONENT_H_