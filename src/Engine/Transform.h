#pragma once
#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include<glm/glm.hpp>
#include <glm/ext.hpp>

#include "Component.h"

namespace myengine
{
	/**
	*Stores transform information of an entity. Automatically added to all entities.
	*/
	class Transform : public Component
	{
	public:
		/**
		*Stores the position.
		*/
		glm::vec3 position;
		/**
		*Stores the rotation.
		*/
		glm::vec3 rotation;
		/**
		*Stores the scale.
		*/
		glm::vec3 scale;

		/**
		*Initializes values of the transform.
		*/
		void onInitialize();
		/**
		*Sets the position of the transform to parameter pos.
		*/
		void SetPosition(glm::vec3 pos);
		/**
		*Sets the rotation of the transform to parameter rot.
		*/
		void SetRotation(glm::vec3 rot);
		/**
		*Sets the scale of the transform to parameter sca.
		*/
		void SetScale(glm::vec3 sca);
		/**
		*Returns the position of the transform.
		*/
		glm::vec3 GetPosition();
		/**
		*Returns the rotation of the transform.
		*/
		glm::vec3 GetRotation();
		/**
		*Returns the scale of the transform.
		*/
		glm::vec3 GetScale();
		/**
		*Generates a model matrix for use in rendering.
		*/
		glm::mat4 GetModelMatrix();
	};
}

#endif