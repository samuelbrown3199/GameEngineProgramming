#include <Engine/MegaHeader.h>
#include <Engine/Texture.h>
#include <Engine/ResourceManager.h>

#include "Player.h"

using namespace myengine;
int main()
{
	std::shared_ptr<Application> app = Application::Initialise("Tech Demo");

	std::shared_ptr<Shader> shader = std::make_shared <Shader>("standard.vs", "standard.fs");
	std::shared_ptr<Texture> texture = app->GetResources()->LoadResource<Texture>("test.png");

	for (int i = 0; i < 100; i++)
	{
		std::shared_ptr<Entity> tri = app->AddEntity();
		tri->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, -10 * i));
		std::shared_ptr<MeshRenderer> pc = tri->AddComponent<MeshRenderer>();
		pc->SetModel("cube.obj");
		pc->SetShader(shader);
		pc->SetTexture(texture);
	}

	std::shared_ptr<Entity> player = app->AddEntity();
	std::shared_ptr<Camera> cam = player->AddComponent<Camera>();
	std::shared_ptr<Player> pl = player->AddComponent<Player>();

	app->AddCamera(cam);

	app->MainLoop();

	return 0;
}