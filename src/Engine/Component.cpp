#include "Component.h"
#include "Entity.h"
#include "Application.h"

namespace myengine
{
	void Component::onInitialize() {};

	void Component::Render() { onRender(); }
	void Component::onRender() {}

	void Component::Tick() { onTick(); }
	void Component::onTick() {}

	std::shared_ptr<Entity> Component::GetEntity()
	{
		return entity.lock();
	}
	std::shared_ptr<Application> Component::GetApplication()
	{
		return GetEntity()->getApplication();
	}

	std::shared_ptr<ResourceManager> Component::GetResources()
	{
		return GetApplication()->GetResources();
	}
}