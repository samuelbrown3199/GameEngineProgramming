#include "Player.h"

#include <Engine/Camera.h>
#include <Engine/InputManager.h>
#include <glm/glm.hpp>

using namespace myengine;

void Player::onInitialize()
{
	cam = GetEntity()->GetComponent<Camera>();
	transform = GetEntity()->GetComponent<Transform>();
}

void Player::CameraControls()
{
	if (InputManager::IfKeyDown(SDL_SCANCODE_W))
	{
		transform->position += movementSpeed * cam->forward;
	}
	if (InputManager::IfKeyDown(SDL_SCANCODE_S))
	{
		transform->position -= movementSpeed * cam->forward;
	}
	if (InputManager::IfKeyDown(SDL_SCANCODE_A))
	{
		glm::vec3 direction = glm::cross(cam->forward, cam->up);
		transform->position -= movementSpeed * direction;
	}
	if (InputManager::IfKeyDown(SDL_SCANCODE_D))
	{
		glm::vec3 direction = glm::cross(cam->forward, cam->up);
		transform->position += movementSpeed * direction;
	}
	if (InputManager::IfKeyDown(SDL_SCANCODE_SPACE))
	{
		transform->position += movementSpeed * cam->up;
	}
	if (InputManager::IfKeyDown(SDL_SCANCODE_X))
	{
		transform->position -= movementSpeed * cam->up;
	}

	MouseMovement();
}

void Player::MouseMovement()
{
	if (InputManager::IfMouseButtonDown(0))
	{
		newMousePos = glm::vec2(InputManager::mouseX, InputManager::mouseY);

		if (firstMouse)
		{
			oldMousePos = newMousePos;
			firstMouse = false;
		}

		float xoffset = newMousePos.x - oldMousePos.x;
		float yoffset = oldMousePos.y - newMousePos.y; // reversed since y-coordinates go from bottom to top
		oldMousePos = newMousePos;

		float sensitivity = 0.1f; // change this value to your liking
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cam->forward = glm::normalize(front);
	}
	else
	{
		firstMouse = true;
	}
}

void Player::onTick()
{
	CameraControls();
	MouseMovement();
}