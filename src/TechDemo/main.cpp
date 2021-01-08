#include <Engine/MegaHeader.h>
#include <Engine/Texture.h>
#include <Engine/ResourceManager.h>
#include <Engine/AudioSource.h>
#include <Engine/AudioListener.h>
#include <Engine/Collider.h>

#include "Player.h"

using namespace myengine;
int main()
{
	std::shared_ptr<Application> app = Application::Initialise("Tech Demo");

	std::shared_ptr<Texture> texture = app->GetResources()->LoadResource<Texture>("test.png");

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
	fc->SetShader(app->standardShader);
	fc->SetTexture(texture);
	floor->AddComponent<Collider>();
	floor->AddComponent<PhysicsBody>(0);

	std::shared_ptr<Entity> physicsTest = app->AddEntity();
	physicsTest->GetComponent<Transform>()->SetPosition(glm::vec3(0, 50, -10));
	std::shared_ptr<MeshRenderer> pc = physicsTest->AddComponent<MeshRenderer>();
	pc->SetModel("cube.obj");
	pc->SetShader(app->standardShader);
	pc->SetTexture(texture);
	physicsTest->AddComponent<Collider>();
	physicsTest->AddComponent<PhysicsBody>(20);


	std::shared_ptr<Entity> quadTest = app->AddEntity();
	quadTest->GetComponent<Transform>()->SetPosition(glm::vec3(0, 5, -5));
	pc = quadTest->AddComponent<MeshRenderer>();
	pc->SetModel("uiquad.obj");
	pc->SetShader(app->standardShader);
	pc->SetTexture(texture);
	std::shared_ptr<AudioSource> au = quadTest->AddComponent<AudioSource>();
	au->SetClip("music.ogg");
	au->loop = true;
	au->gain = 0.1;
	au->Play();

	std::shared_ptr<Entity> player = app->AddEntity();
	player->GetComponent<Transform>()->SetPosition(glm::vec3(0, 5, 0));
	std::shared_ptr<Camera> cam = player->AddComponent<Camera>();
	std::shared_ptr<Player> pl = player->AddComponent<Player>();
	player->AddComponent<AudioListener>();

	app->AddCamera(cam);

	std::shared_ptr<UiSystem> testUI = app->BindUI<UiSystem>();
	testUI->AddUiElement<UiComponent>();

	app->MainLoop();

	return 0;
}