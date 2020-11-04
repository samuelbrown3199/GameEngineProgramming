#include <exception>
#include <memory>
#include <vector>

#include <SDL.h>
#include <GL/glew.h>

namespace myengine
{
	class ResourceManager;
	class Screen;
	class Entity;

	class Application
	{
	private:
		Application();

		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Application> self;
		std::shared_ptr<ResourceManager> resources;
		std::shared_ptr<Screen> screen;

		SDL_Window* window;

		bool loop = true;

		void UpdateScreenSize();

	public:
		static std::shared_ptr<Application> Initialise();
		void Start();

		std::shared_ptr<Screen> GetScreen();
		std::shared_ptr<ResourceManager> GetResources();
		std::shared_ptr<Entity> AddEntity();
	};
}