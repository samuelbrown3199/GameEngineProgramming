#pragma once
#ifndef CAMERA_H_
#define CAMERA_H_

#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtx/transform.hpp>

#include "Component.h"

namespace myengine
{
	class Camera : public Component
	{
	private:

		bool firstMouse = true;
		float pitch = 0.0f, yaw = -90.0f;

		const float movementSpeed = 0.1f;
		glm::vec2 oldMousePos, newMousePos;

		glm::vec3 up;

	public:

		int time = 0;

		void onInitialize();
		void onTick();

		glm::mat4 view;

	};
}
#endif

