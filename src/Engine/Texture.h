#pragma once
#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glew.h>

#include "Resource.h"

namespace myengine
{
	/**
	*A texture class. Inherits from resource for use in components.
	*/
	class Texture : public Resource
	{
	private:

	public:
		/**
		*Unique texture ID for use in binding.
		*/
		GLuint textureID;

		/**
		*Loads the texture.
		*/
		void OnLoad();
	};
}

#endif