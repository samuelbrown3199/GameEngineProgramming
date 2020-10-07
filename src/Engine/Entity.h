#include<vector>
#include<memory>

namespace myengine
{
	class Component;

	class Entity
	{
	private:
		std::vector<std::shared_ptr<Component>> components;

	public:
		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			components.push_back(rtn);

			return rtn;
		}

	};
}