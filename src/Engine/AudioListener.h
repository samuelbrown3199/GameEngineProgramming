#include "Component.h"
#include "Transform.h"

namespace myengine
{
	/**
	*Sets the audio listening source.
	*/
	class AudioListener : public Component
	{
	private:

		std::shared_ptr<Transform> listenerTransform;

	public:
		/**
		*Initializes the listener transform.
		*/
		void onInitialize();
		/**
		*Updates the audio listener position.
		*/
		void onTick();

	};
}