#include <bugl.h>

#include "Model.h"

namespace myengine
{
	void Model::OnLoad()
	{
		vaoID = buLoadModel(resourcePath, &drawCount);
	}
}