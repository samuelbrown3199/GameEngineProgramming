#pragma once
#ifndef AUDIOCLIP_H_
#define AUDIOCLIP_H_

#include <string>
#include <vector>

#include <AL/al.h>

#include "Resource.h"

namespace myengine
{
	/**
	*Stores an audio file into memory.
	*/
	class AudioClip : public Resource
	{
	public:
		ALuint audioClipID = 0;
		void OnLoad();

	private:
		/**
		*Loads an ogg file.
		*/
		void LoadOgg(const std::string& fileDirectory, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
	};
}

#endif