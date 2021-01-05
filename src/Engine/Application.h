#pragma once
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <exception>
#include <memory>
#include <vector>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>

#include "Physics.h"
#include "UiSystem.h"

namespace myengine
{
	class Camera;
	class ResourceManager;
	class Screen;
	class Entity;
	class Shader;
	/**
	*Setups the engine for use in simulations or games.
	*/
	class Application
	{
	private:
		Application();

		/**
		*Stores a pointer to the current audio device.
		*/
		ALCdevice* audioDevice;
		/**
		*Stores a pointer to the current audio context.
		*/
		ALCcontext* audioContext;
		/**
		*Stores a list of the current entities in the scene.
		*/
		std::vector<std::shared_ptr<Entity>> entities;
		/**
		*Stores a list of UIs
		*/
		std::vector<std::shared_ptr<UiSystem>> uis;
		/**
		*Stores a weak pointer to itself.
		*/
		std::weak_ptr<Application> self;
		/**
		*Stores the resource manager.
		*/
		std::shared_ptr<ResourceManager> resources;
		/**
		*Stores information about the screen.
		*/
		std::shared_ptr<Screen> screen;
		/**
		*Stores a pointer to the application window.
		*/
		SDL_Window* window;
		/**
		*Determines whether the main engine loop should run.
		*/
		bool loop = true;
		/**
		*Updates the screen size.
		*/
		void UpdateScreenSize();

	public:
		/**
		*Stores the current framerate.
		*/
		double frameRate;

		std::shared_ptr<Shader> standardShader;
		std::shared_ptr<Shader> uiShader;
		/**
		*Initializes the engine, starting required libraries, and making a window.
		*/
		static std::shared_ptr<Application> Initialise(std::string windowName);
		/**
		*Starts the main engine loop.
		*/
		void MainLoop();
		/**
		*Returns a shared pointer to the screen object.
		*/
		std::shared_ptr<Screen> GetScreen();
		/**
		*Returns a shared pointer to the resource manager.
		*/
		std::shared_ptr<ResourceManager> GetResources();
		/**
		*Creates an entity and stores it in the entity list. Returns the created entity as a shared pointer.
		*/
		std::shared_ptr<Entity> AddEntity();
		/**
		*Stores the main camera.
		*/
		std::shared_ptr<Camera> camera;
		/**
		*Tells the engine what to use as the main camera.
		*/
		void AddCamera(std::shared_ptr<Camera> cam);
		/**
		*Creates, initializes and adds a UI to the application.
		*/
		template<typename T>
		std::shared_ptr<T> BindUI()
		{

			std::shared_ptr<T> ui = std::make_shared<T>();
			ui->InitializeUI();
			ui->application = self;
			ui->self = ui;

			uis.push_back(ui);
			return ui;
		}
		template<typename T>
		std::shared_ptr<T> GetUI()
		{
			for (size_t ui = 0; ui < uis.size(); ui++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast(uis.at(ui));
				if (rtn)
				{
					return rtn;
				}
			}

			std::cout << "Could not find UI of type!" << std::endl;
			throw std::exception();
		}
	};
}

#endif