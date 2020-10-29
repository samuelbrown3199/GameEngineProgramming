#include<vector>
#include<memory>

namespace myengine
{
	class Application;
	class Component;

	class Entity
	{
	friend class myengine::Application;

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Application> application;
		std::weak_ptr<Entity> self;
	public:
		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);
			rtn->onInitialize();

			return rtn;
		}

		template<typename T>
		std::shared_ptr<T> GetComponent()
		{
			std::shared_ptr<T> rtn;
			for (size_t i = 0; i < components.size(); i++)
			{
				rtn = std::dynamic_pointer_cast<T>(components.at(i));
				if (!rtn) continue;

				return rtn;
			}

			throw std::exception();
		}

		void Render();
		void Tick();

		std::shared_ptr<Application> getApplication();
	};
}