#include "Application.h"
#include "Screen.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	Application::Application()
	{

	}

	std::shared_ptr<Application> Application::Initialise()
	{
		//std::shared_ptr<Application> rtn = std::make_shared<Application>();
		std::shared_ptr<Application> rtn(new Application());
		rtn->self = rtn;

		//rtn->resources = std::make_shared<ResourceManager>();
		rtn->screen = std::make_shared<Screen>();

		rtn->window = SDL_CreateWindow("Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rtn->screen->GetScreenWidth(), rtn->screen->GetScreenHeight(), SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		return rtn;
	}

	void Application::Start()
	{
		SDL_Event e = { 0 };

		while (loop)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					loop = false;
				}
			}
			UpdateScreenSize();

			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->Tick();
			}

			glClearColor(0.0f, 0.45f, 0.45f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->Render();
			}

			SDL_GL_SwapWindow(window);
		}
	}

	void Application::UpdateScreenSize()
	{
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		screen->SetScreenHeight(h);
		screen->SetScreenWidth(w);
	}

	std::shared_ptr<Screen> Application::GetScreen()
	{
		return screen;
	}

	std::shared_ptr<Entity> Application::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->application = self;
		rtn->self = rtn;
		std::shared_ptr<Transform> transform = rtn->AddComponent<Transform>();

		entities.push_back(rtn);
		return rtn;
	}
}