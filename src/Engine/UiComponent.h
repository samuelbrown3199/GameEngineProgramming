#pragma once
#ifndef UICOMPONENT_H_
#define UICOMPONENT_H_

#include <memory>

#include<SDL.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Model.h"
#include "Texture.h"
#include "Application.h"
#include "ResourceManager.h"

namespace myengine
{
	class UiSystem;

	/**
	*Stores a UI element screen position;
	*/
	struct UiRect
	{
		glm::vec2 position;
		glm::vec2 scale;

		glm::mat4 GetScreenPos()
		{
			glm::mat4 screenPos(1.0f);

			screenPos = glm::translate(screenPos, glm::vec3(position, -1.0f));
			screenPos = glm::scale(screenPos, glm::vec3(scale, 1.0f));

			return screenPos;
		}
	};

	/**
	*Ui base component for UI elements to inherit from.
	*/
	class UiComponent
	{
	private:

		std::shared_ptr<Model> uiQuad;

	public:

		/**
		*Sets up the quad for use in rendering.
		*/
		void InitializeQuad();
		/**
		*Stores a weak pointer to the parent ui system.
		*/
		std::weak_ptr<UiSystem> parentSystem;
		/**
		*Stores the rectangle the UI element uses.
		*/
		UiRect rect;
		/**
		*Stores the UI element texture.
		*/
		std::shared_ptr<Texture> texture;
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