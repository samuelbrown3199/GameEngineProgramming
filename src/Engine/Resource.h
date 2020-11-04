#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

namespace myengine
{
	class Resource
	{
	public:
		std::string resourcePath;

		virtual void OnLoad();
	};
}

#endif
