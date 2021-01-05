#pragma once
#ifndef UISYSTEM_H_
#define UISYSTEM_H_

#include <iostream>
#include <memory>
#include <vector>

namespace myengine
{
	class UiComponent;
	class Shader;
	class Application;

	/**
	*UIs will inherit from this base class to create functional UI.
	*/
	class UiSystem
	{
		/**
		*Stores a list of all UI elements.
		*/
		std::vector<std::shared_ptr<UiComponent>> uiElements;

	public:

		std::weak_ptr<UiSystem> self;
		/**
		*Used to access application.
		*/
		std::weak_ptr<Application> application;
		/**
		*
		*/
		std::shared_ptr<Shader> uiShader;
		/**
		*Used to determine whether the UI is open. If false the UI wont call OnUpdate or the render function.
		*/
		bool open = false;
		/**
		*Returns a shared pointer to the application.
		*/
		std::shared_ptr<Application> GetApplication();
		/**
		*Inheriting classes can initialize the UI in this function.
		*/
		virtual void InitializeUI();
		/**
		*Calls the on update function every frame.
		*/
		void UpdateUI();
		/**
		*Implemented via inheriting classes. Used to provide functionality to the UI.
		*/
		virtual void OnUpdate();
		/**
		*Renders the UI.
		*/
		void RenderUI();

		template<typename T>
		std::shared_ptr<T> AddUiElement()
		{
			std::shared_ptr<T> comp = std::make_shared<T>();
			comp->parentSystem = self;
			comp->InitializeQuad();

			uiElements.push_back(comp);

			return comp;
		}
	};
}

#endif