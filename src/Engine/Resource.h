#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

namespace myengine
{
	/**
	*Resources inherit from this class, e.g Textures & Models.
	*/
	class Resource
	{
	public:
		/**
		*Stores the file path of the resource, used as an identifier.
		*/
		std::string resourcePath;
		/**
		*When a resource is loaded this function is called to manage the data from the file.
		*/
		virtual void OnLoad();
	};
}

#endif
