#include <Vector>
#include <Memory>
#include <string>

#include "Resource.h"

namespace myengine
{
	class ResourceManager
	{
	private:
		std::vector<std::shared_ptr<Resource>> resources;

	public:

		/*template<typename T>
		std::shared_ptr<T> LoadResource(std::string path)
		{
			for (size_t i = 0; i < resources.i++)
			{
				if (resources.at(i)->resourcePath == path)
				{
					return resources.at(i);
				}
			}

			std::shared_ptr<T> newResource = std::make_shared<T>(path);
			resources.push_back(newResource);
			return newResource;
		}*/
	};
}