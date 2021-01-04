#include "Font.h"

namespace myengine
{
	void Font::OnLoad()
	{
		fontData = TTF_OpenFont(resourcePath.c_str(), 24);
	}
}