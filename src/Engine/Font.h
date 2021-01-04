#include "Resource.h"

#include<memory>

#include <SDL_ttf.h>

namespace myengine
{
	/**
	*A resource used to store a font file.
	*/
	class Font : public Resource
	{
		TTF_Font* fontData;
		void OnLoad();
	};
}