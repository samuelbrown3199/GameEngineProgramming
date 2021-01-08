#include<vector>
#include<memory>

namespace myengine
{
	class Application;
	class Component;

	/**
	*The entity class. Stores components for game data and functionality
	*/
	class Entity
	{
	friend class myengine::Application;

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Application> application;
		std::weak_ptr<Entity> self;
	public:
		/**
		*Adds a component of the passed type to the entity.
		*/
		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);
			rtn->onInitialize();

			return rtn;
		}
		/**
		*Adds a component of the passed type to the entity along with parameters.
		*/
		template<typename T, typename ... Args>
		std::shared_ptr<T> AddComponent(Args&&... args)
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);
			rtn->onInitialize(std::forward<Args>(args)...);

			return rtn;
		}
		/**
		*Returns the component of the passed type.
		*/
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

		/**
		*The Render function for the entity. Loops over every component and calls their render function.
		*/
		void Render();
		/**
		*The Tick function for the entity. Loops over every component and calls their tick function.
		*/
		void Tick();

		/**
		*Returns the application class linked from the entity.
		*/
		std::shared_ptr<Application> GetApplication();
	};
}