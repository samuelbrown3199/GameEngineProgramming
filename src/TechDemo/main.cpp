#include <Engine/MegaHeader.h>
#include <Engine/Texture.h>
#include <Engine/ResourceManager.h>
#include <Engine/AudioSource.h>
#include <Engine/AudioListener.h>
#include <Engine/Collider.h>

#include "Player.h"

#include <time.h>

using namespace myengine;
int main()
{
	std::shared_ptr<Application> app = Application::Initialise("Tech Demo");

	std::shared_ptr<Texture> texture = app->GetResources()->LoadResource<Texture>("test.png");
	std::shared_ptr<Texture> texture2 = app->GetResources()->LoadResource<Texture>("metal.png");

	srand(time(NULL));

	const int amount = 10;

	for (int x = 0; x < amount; x++)
	{
		for (int z = 0; z < amount; z++)
		{
			for (int y = 0; y < amount; y++)
			{
				std::shared_ptr<Entity> physicsTest = app->AddEntity();
				physicsTest->GetComponent<Transform>()->SetPosition(glm::vec3(25 + (-5 * x)+rand() % 5, 50 + (5*y) +rand() % 5, -30 + (-5 * z) + rand() % 5));
				physicsTest->GetComponent<Transform>()->SetRotation(glm::vec3(rand()%360, rand() % 360, rand() % 360));
				std::shared_ptr<MeshRenderer> pc = physicsTest->AddComponent<MeshRenderer>();
				pc->SetModel("cube.obj");
				pc->SetShader(app->standardShader);
				pc->SetTexture(texture);
				physicsTest->AddComponent<Collider>(Collider::ColliderShape::box);
				physicsTest->AddComponent<PhysicsBody>(20);
			}
		}
	}

	std::shared_ptr<Entity> floor = app->AddEntity();
	floor->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, 0));
	floor->GetComponent<Transform>()->SetScale(glm::vec3(100, 1, 100));
	std::shared_ptr<MeshRenderer> fc = floor->AddComponent<MeshRenderer>();
	fc->SetModel("cube.obj");
	fc->SetShader(app->standardShader);
	fc->SetTexture(texture);
	floor->AddComponent<Collider>(Collider::ColliderShape::box);
	floor->AddComponent<PhysicsBody>(0.0f);
	std::shared_ptr<AudioSource> au = floor->AddComponent<AudioSource>();
	au->SetClip("music.ogg");
	au->loop = true;
	au->gain = 1.0f;
	//au->Play();

	std::shared_ptr<Entity> player = app->AddEntity();
	player->GetComponent<Transform>()->SetPosition(glm::vec3(0, 5, 0));
	std::shared_ptr<Camera> cam = player->AddComponent<Camera>();
	std::shared_ptr<Player> pl = player->AddComponent<Player>();
	player->AddComponent<AudioListener>();

	app->AddCamera(cam);

	std::shared_ptr<Entity> testCube = app->AddEntity();
	testCube->GetComponent<Transform>()->SetPosition(glm::vec3(0, 5, 0));
	testCube->GetComponent<Transform>()->SetRotation(glm::vec3(65, 54, 33));
	testCube->GetComponent<Transform>()->SetScale(glm::vec3(1, 1, 1));
	fc = testCube->AddComponent<MeshRenderer>();
	fc->SetModel("cube.obj");
	fc->SetShader(app->standardShader);
	fc->SetTexture(texture2);
	std::shared_ptr<AudioSource> as = testCube->AddComponent<AudioSource>();
	as->SetClip("test2.ogg");
	as->gain = 1.0f;
	as->loop = true;
	as->Play();

	app->MainLoop();

	return 0;
}