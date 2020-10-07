#include "Application.h"
#include "Entity.h"

namespace myengine
{
	Application::Application()
	{

	}

	std::shared_ptr<Application> Application::Initialise()
	{
		//std::shared_ptr<Application> rtn = std::make_shared<Application>();
		std::shared_ptr<Application> rtn(new Application());
		return rtn;
	}

	void Application::Start()
	{

	}

	std::shared_ptr<Entity> Application::AddEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		entities.push_back(rtn);
		return rtn;
	}
}