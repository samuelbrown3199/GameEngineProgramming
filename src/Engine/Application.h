#include <exception>
#include <memory>
#include <vector>
#include <string>

#include <SDL.h>
#include <GL/glew.h>
#include <AL/al.h>
#include <AL/alc.h>

namespace myengine
{
	class Camera;
	class ResourceManager;
	class Screen;
	class Entity;
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
	};
}