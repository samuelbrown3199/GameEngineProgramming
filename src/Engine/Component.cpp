#include "Component.h"
#include "Entity.h"

namespace myengine
{
	void Component::onInitialize() {};

	void Component::Render() { onRender(); }
	void Component::onRender() {}

	void Component::Tick() { onTick(); }
	void Component::onTick() {}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}
	std::shared_ptr<Application> Component::getApplication()
	{
		return getEntity()->getApplication();
	}
}