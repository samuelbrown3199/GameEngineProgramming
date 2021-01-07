#include "Component.h"

#include <AL/al.h>

#include "Transform.h"
#include "AudioClip.h"

namespace myengine
{
	/**
	*Acts as an audio source.
	*/
	class AudioSource : public Component 
	{
	private:

		ALuint sourceID;
		std::shared_ptr<Transform> sourceTransform;
		std::shared_ptr<AudioClip> clip;

	public:
		
		bool loop = false;
		float pitch = 1;
		float gain = 1;
		glm::vec3 velocity = glm::vec3(0,0,0);

		~AudioSource();

		void onInitialize();
		void onTick();

		void SetClip(std::string fileName);
		void Play();
	};
}