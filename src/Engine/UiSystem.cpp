#include "UiSystem.h"
#include "Application.h"
#include "UiComponent.h"

namespace myengine
{
	std::shared_ptr<Application> UiSystem::GetApplication()
	{
		return application.lock();
	}

	void UiSystem::InitializeUI()
	{

	}

	void UiSystem::UpdateUI()
	{
		if (open)
		{
			OnUpdate();
		}
	}
	void UiSystem::OnUpdate()
	{

	}
	void UiSystem::RenderUI()
	{
		/*if (open)
		{*/
			for (size_t ui = 0; ui < uiElements.size(); ui++)
			{
				uiElements.at(ui)->RenderUiElement();
			}
		//}
	}
}