#include <chrono>

#include "Application.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	Application::Application()
	{

	}

	std::shared_ptr<Application> Application::Initialise(std::string windowName)
	{
		//std::shared_ptr<Application> rtn = std::make_shared<Application>();
		std::shared_ptr<Application> rtn(new Application());
		rtn->self = rtn;

		if (SDL_Init(SDL_INIT_EVERYTHING) == -1) //initialise SDL, if it fails, exit the program
		{
			std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
			throw std::exception();
		}
		rtn->audioDevice = alcOpenDevice(NULL);
		if (!rtn->audioDevice)
		{
			std::cout << "Application failed to initialize audio device!" << std::endl;
		}
		rtn->audioContext = alcCreateContext(rtn->audioDevice, NULL);
		if (!rtn->audioContext)
		{
			std::cout << "Application failed to initialize audio context!" << std::endl;
			alcCloseDevice(rtn->audioDevice);
		}
		if (!alcMakeContextCurrent(rtn->audioContext))
		{
			std::cout << "Application failed to assign audio context!" << std::endl;
			alcDestroyContext(rtn->audioContext);
			alcCloseDevice(rtn->audioDevice);
		}
		if (TTF_Init() == -1) //initialise TTF for use with fonts and text later, if it couldnt initialise, close the program
		{
			std::cout << "SDL_TTF couldn't intialise" << std::endl;
			throw std::exception();
		}
		rtn->resources = std::make_shared<ResourceManager>();
		rtn->screen = std::make_shared<Screen>();

		rtn->window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rtn->screen->GetScreenWidth(), rtn->screen->GetScreenHeight(), SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}
		rtn->sdlRenderer = SDL_CreateRenderer(rtn->window, -1, SDL_RENDERER_ACCELERATED);
		if (rtn->sdlRenderer == nullptr)
		{
			std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
			throw std::exception();
		}

		return rtn;
	}

	void Application::MainLoop()
	{
		SDL_Event e = { 0 };

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f, 0.45f, 0.45f, 1.0f);

		Uint32 frameStart;

		while (loop)
		{
			frameStart = SDL_GetTicks();

			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->Render();
			}
			SDL_GL_SwapWindow(window);

			double frameTime = SDL_GetTicks() - frameStart;
			double fps = 1000.0f / frameTime;
			Physics::deltaT = 1.0f / fps;

			std::cout << "FPS: " << fps << std::endl;
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

	std::shared_ptr<ResourceManager> Application::GetResources()
	{
		return resources;
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

	void Application::AddCamera(std::shared_ptr<Camera> cam)
	{
		camera = cam;
	}
}