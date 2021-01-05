#pragma once
#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <vector>
#include <memory>
#include <string>

namespace myengine
{
	class Resource;

	/**
	*Handles resources for use in the engine. Handles loading and unloading of data.
	*/
	class ResourceManager
	{
	private:
		/**
		*Stores all currently loaded resources.
		*/
		std::vector<std::shared_ptr<Resource>> resources;

	public:

		/**
		*Loads a resource of the passed resource type. Adds it the loaded resource list.
		*/
		template<typename T>
		std::shared_ptr<T> LoadResource(std::string path)
		{
			for (size_t ri = 0; ri < resources.size(); ri++)
			{
				if (resources.at(ri)->resourcePath == path)
				{
					std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(resources.at(ri));
					if (rtn)
					{
						return rtn;
					}
				}
			}

			std::shared_ptr<T> newResource = std::make_shared<T>();
			newResource->resourcePath = path;
			newResource->OnLoad();
			resources.push_back(newResource);
			return newResource;
		}
	};
}

#endif