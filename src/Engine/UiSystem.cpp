#include "UiSystem.h"
#include "Application.h"
#include "UiComponent.h"

namespace myengine
{
	std::shared_ptr<Application> UiSystem::GetApplication()
	{
		return application.lock();
	}

	void UiSystem::UpdateUI()
	{

	}
	void UiSystem::RenderUI()
	{
		for (size_t ui = 0; ui < uiElements.size(); ui++)
		{
			uiElements.at(ui)->RenderUiElement();
		}
	}
}