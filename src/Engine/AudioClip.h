#include <string>
#include <vector>

#include <AL/al.h>

#include "Resource.h"

namespace myengine
{
	class AudioClip : public Resource
	{
	public:
		ALuint audioClipID;
		void OnLoad();

	private:
		void LoadOgg(std::string& fileDirectory, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
	};
}