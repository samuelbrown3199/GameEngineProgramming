#include <Engine/Application.h>

using namespace myengine;

int main()
{
	std::shared_ptr<Application> app = Application::Initialise();
	app->Start();

	return 0;
}