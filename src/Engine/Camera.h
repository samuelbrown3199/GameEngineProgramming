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
	/**
	*Camera component. Used in rendering.
	*/
	class Camera : public Component
	{
	private:

	public:

		glm::vec3 up;
		glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);

		int time = 0;

		void onInitialize();
		void onTick();

		glm::mat4 view;

	};
}
#endif

