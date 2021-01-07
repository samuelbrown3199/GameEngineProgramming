#include "AudioListener.h"
#include "Entity.h"

#include <AL/al.h>

namespace myengine
{
	void AudioListener::onInitialize()
	{
		listenerTransform = GetEntity()->GetComponent<Transform>();
	}

	void AudioListener::onTick()
	{
		alListener3f(AL_POSITION, listenerTransform->position.x, listenerTransform->position.y, listenerTransform->position.z);
		alListener3f(AL_ORIENTATION, listenerTransform->rotation.x, listenerTransform->rotation.y, listenerTransform->rotation.z);
	}
}