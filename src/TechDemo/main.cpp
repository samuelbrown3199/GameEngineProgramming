#include <Engine/MegaHeader.h>

#include "Player.h"

using namespace myengine;

int main()
{
	std::shared_ptr<Application> app = Application::Initialise();

	std::shared_ptr<Entity> pe = app->AddEntity();
	pe->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, -10));

	std::shared_ptr<TriangleRenderer> pc = pe->AddComponent<TriangleRenderer>();

	app->Start();

	return 0;
}