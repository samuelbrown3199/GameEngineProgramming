#include "Application.h"

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
}