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

	for (int x = 0; x < 10; x++)
	{
		for (int z = 0; z < 10; z++)
		{
			for (int y = 0; y < 10; y++)
			{
				std::shared_ptr<Entity> physicsTest = app->AddEntity();
				physicsTest->GetComponent<Transform>()->SetPosition(glm::vec3(25 + (-5 * x), 50 + (10*y), -30 + (-5 * z)));
				physicsTest->GetComponent<Transform>()->SetRotation(glm::vec3(rand()%360, rand() % 360, rand() % 360));
				std::shared_ptr<MeshRenderer> pc = physicsTest->AddComponent<MeshRenderer>();
				pc->SetModel("sphere.obj");
				pc->SetShader(app->standardShader);
				pc->SetTexture(texture);
				physicsTest->AddComponent<Collider>(Collider::ColliderShape::sphere);
				physicsTest->AddComponent<PhysicsBody>(1);
			}
		}
	}

	std::shared_ptr<Entity> floor = app->AddEntity();
	floor->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, 0));
	floor->GetComponent<Transform>()->SetScale(glm::vec3(1000, 1, 1000));
	std::shared_ptr<MeshRenderer> fc = floor->AddComponent<MeshRenderer>();
	fc->SetModel("cube.obj");
	fc->SetShader(app->standardShader);
	fc->SetTexture(texture);
	floor->AddComponent<Collider>(Collider::ColliderShape::box);
	floor->AddComponent<PhysicsBody>(0);

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

	app->MainLoop();

	return 0;
}