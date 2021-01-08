#include "AudioSource.h"

#include "Entity.h"
#include "Application.h"
#include "ResourceManager.h"

namespace myengine
{
	AudioSource::~AudioSource()
	{
		alDeleteSources(1, &sourceID);
	}

	void AudioSource::onInitialize()
	{
		sourceTransform = GetEntity()->GetComponent<Transform>();
		alGenSources(1, &sourceID); 
	}

	void AudioSource::onTick()
	{
		alSource3f(sourceID, AL_POSITION, sourceTransform->position.x, sourceTransform->position.y, sourceTransform->position.z);
		alSource3f(sourceID, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
		
		alSourcei(sourceID, AL_LOOPING, loop);
	}

	void AudioSource::SetClip(std::string fileName)
	{
		clip = GetApplication()->GetResources()->LoadResource<AudioClip>(fileName);
	}

	void AudioSource::Play()
	{
		alSourcef(sourceID, AL_PITCH, pitch);
		alSourcef(sourceID, AL_GAIN, gain);
		alSourcei(sourceID, AL_BUFFER, clip->audioClipID);
		alSourcePlay(sourceID);
	}
}