#include <Engine/MegaHeader.h>
#include <iostream>

using namespace myengine;

class Player : public Component
{
private:

	std::shared_ptr<Camera> cam;

	void CameraControls();
	void MouseMovement();

public:
	void onInitialize();
	void onTick();
};