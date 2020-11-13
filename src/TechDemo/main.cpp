#include <Engine/MegaHeader.h>

#include "Player.h"

using namespace myengine;

int main()
{
	std::shared_ptr<Application> app = Application::Initialise();

	std::shared_ptr<Entity> tri = app->AddEntity();
	tri->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, -10));

	std::shared_ptr<TriangleRenderer> pc = tri->AddComponent<TriangleRenderer>();

	std::shared_ptr<Entity> player = app->AddEntity();
	std::shared_ptr<Camera> cam = player->AddComponent<Camera>();
	std::shared_ptr<Player> pl = player->AddComponent<Player>();

	app->Start();

	return 0;
}