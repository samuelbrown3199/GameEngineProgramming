#include "UiComponent.h"
#include "InputManager.h"

namespace myengine
{
	bool UiComponent::CheckForMouseHover()
	{
		if (InputManager::mouseX > rect.x && InputManager::mouseX < rect.x + rect.w && InputManager::mouseY > rect.y && InputManager::mouseY < rect.y + rect.h)
		{
			return true;
		}

		return false;
	}

	bool UiComponent::HasClicked()
	{
		if (CheckForMouseHover())
		{
			if (InputManager::IfMouseButtonDown(0))
			{
				return true;
			}
		}

		return false;
	}

	void UiComponent::RenderUiElement()
	{

	}
}