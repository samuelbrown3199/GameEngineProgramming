#pragma once

#include <memory>

namespace myengine
{
	class Entity;
	class Application;
	class ResourceManager;

	/**
	*Component class for inheriting from.
	*/
	class Component
	{
	
		friend class myengine::Entity;
		private:

			std::weak_ptr<Entity> entity;

		public:
			/**
			*Initialize function for overriding in inheriting classes.
			*/
			virtual void onInitialize();

			void Render();
			/**
			*Render function for overriding in inheriting classes.
			*/
			virtual void onRender();

			void Tick();
			/**
			*Tick function for overriding in inheriting classes.
			*/
			virtual void onTick();

			/**
			*Returns the entity that the component is attached to.
			*/
			std::shared_ptr<Entity> GetEntity();
			/**
			*Returns the application object.
			*/
			std::shared_ptr<Application> GetApplication();
			/**
			*Returns the resource manager object for use in loading resources.
			*/
			std::shared_ptr<ResourceManager> GetResources();
	};
}