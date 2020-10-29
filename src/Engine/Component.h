#pragma once

#include <memory>

namespace myengine
{
	class Entity;
	class Application;

	class Component
	{
	
	friend class myengine::Entity;
	private:

		std::weak_ptr<Entity> entity;

	public:
		virtual void onInitialize();

		void Render();
		virtual void onRender();

		void Tick();
		virtual void onTick();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Application> getApplication();
	};
}