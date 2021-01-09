#include "Component.h"

#include <AL/al.h>

#include "Transform.h"
#include "AudioClip.h"

namespace myengine
{
	/**
	*Acts as an audio source. Works in 3D only with mono channel audio files, otherwise the audio listener and source locations will not matter.
	*/
	class AudioSource : public Component 
	{
	private:

		ALuint sourceID;
		std::shared_ptr<Transform> sourceTransform;
		std::shared_ptr<AudioClip> clip;

	public:
		/**
		*Determines whether the audio source will loop.
		*/
		bool loop = false;
		/**
		*Determines the audio pitch.
		*/
		float pitch = 1;
		/**
		*Determines the audio volume.
		*/
		float gain = 1;
		glm::vec3 velocity = glm::vec3(0,0,0);

		~AudioSource();

		void onInitialize();
		void onTick();

		/**
		*Changes the audio clip that the source will use.
		*/
		void SetClip(std::string fileName);
		/**
		*Plays the current audio clip with the current audio source settings.
		*/
		void Play();
		/**
		*Stops the audio source from playing.
		*/
		void Stop();
	};
}