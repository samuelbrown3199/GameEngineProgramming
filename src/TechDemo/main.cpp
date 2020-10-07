#include <Engine/MegaHeader.h>

#include "Player.h"

using namespace myengine;

int main()
{
	std::shared_ptr<Application> app = Application::Initialise();

	std::shared_ptr<Entity> pe = app->AddEntity();
	std::shared_ptr<Component> pc = pe->AddComponent<Player>();

	app->Start();

	return 0;
}