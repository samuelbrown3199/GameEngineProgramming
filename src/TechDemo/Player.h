#include <Engine/MegaHeader.h>
#include <iostream>

using namespace myengine;

class Player : public Component
{
private:

	std::shared_ptr<Camera> cam;
	std::shared_ptr<Transform> transform;

	float movementSpeed = 0.1f;
	bool firstMouse = true;
	float pitch = 0.0f, yaw = -90.0f;

	glm::vec2 oldMousePos, newMousePos;

	void CameraControls();
	void MouseMovement();

public:
	void onInitialize();
	void onTick();
};