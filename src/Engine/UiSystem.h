#include <memory>
#include <vector>

namespace myengine
{
	class Application;
	class UiComponent;

	/**
	*UIs will inherit from this base class to create functional UI.
	*/
	class UiSystem
	{
		/**
		*Used to access Sdl renderer.
		*/
		std::weak_ptr<Application> application;
		/**
		*Stores a list of all UI elements.
		*/
		std::vector<std::shared_ptr<UiComponent>> uiElements;

	public:
		/**
		*Returns a shared pointer to the application.
		*/
		std::shared_ptr<Application> GetApplication();
		/**
		*Call various functions in here using the UI elements.
		*/
		virtual void UpdateUI();
		/**
		*Renders the UI.
		*/
		void RenderUI();
	};
}