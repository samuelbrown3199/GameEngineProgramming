#include "Entity.h"
#include "Component.h"

namespace myengine
{
	void Entity::Render()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->Render();
		}
	}

	void Entity::Tick()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->Tick();
		}
	}

	std::shared_ptr<Application> Entity::getApplication()
	{
		return application.lock();
	}
}