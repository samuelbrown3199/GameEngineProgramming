#include <Engine/MegaHeader.h>

using namespace myengine;

int main()
{
	std::shared_ptr<Application> app = Application::Initialise();

	std::shared_ptr<Entity> pe = app->AddEntity();
	std::shared_ptr<Component> pc = pe->AddComponent<Component>();

	app->Start();

	return 0;
}