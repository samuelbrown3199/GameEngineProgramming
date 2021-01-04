#include <Engine/MegaHeader.h>
#include <Engine/Texture.h>
#include <Engine/ResourceManager.h>
#include <Engine/AudioClip.h>

#include "Player.h"

using namespace myengine;
int main()
{
	std::shared_ptr<Application> app = Application::Initialise("Tech Demo");

	std::shared_ptr<Shader> shader = std::make_shared <Shader>("standard.vs", "standard.fs");
	std::shared_ptr<Texture> texture = app->GetResources()->LoadResource<Texture>("test.png");
	//std::shared_ptr<AudioClip> audioClip = app->GetResources()->LoadResource<AudioClip>("testsound.ogg");

	/*for (int i = 0; i < 100; i++)
	{
		std::shared_ptr<Entity> floor = app->AddEntity();
		floor->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, -20 * i));
		std::shared_ptr<MeshRenderer> pc = floor->AddComponent<MeshRenderer>();
		pc->SetModel("floor.obj");
		pc->SetShader(shader);
		pc->SetTexture(texture);
	}*/

	std::shared_ptr<Entity> floor = app->AddEntity();
	floor->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, 0));
	floor->GetComponent<Transform>()->SetScale(glm::vec3(1000, 1, 1000));
	std::shared_ptr<MeshRenderer> fc = floor->AddComponent<MeshRenderer>();
	fc->SetModel("cube.obj");
	fc->SetShader(shader);
	fc->SetTexture(texture);

	std::shared_ptr<Entity> physicsTest = app->AddEntity();
	physicsTest->GetComponent<Transform>()->SetPosition(glm::vec3(0, 50, -10));
	std::shared_ptr<MeshRenderer> pc = physicsTest->AddComponent<MeshRenderer>();
	pc->SetModel("cube.obj");
	pc->SetShader(shader);
	pc->SetTexture(texture);
	physicsTest->AddComponent<PhysicsBody>();

	std::shared_ptr<Entity> player = app->AddEntity();
	player->GetComponent<Transform>()->SetPosition(glm::vec3(0, 5, 0));
	std::shared_ptr<Camera> cam = player->AddComponent<Camera>();
	std::shared_ptr<Player> pl = player->AddComponent<Player>();

	app->AddCamera(cam);

	app->MainLoop();

	return 0;
}