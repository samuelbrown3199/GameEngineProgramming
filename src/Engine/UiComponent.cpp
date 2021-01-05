#include "UiComponent.h"
#include "InputManager.h"

#include "UiSystem.h"

#include "Shader.h" //all temp
#include "Screen.h"

namespace myengine
{
	void UiComponent::InitializeQuad()
	{
		uiQuad = parentSystem.lock()->GetApplication()->GetResources()->LoadResource<Model>("uiquad.obj");
		texture = parentSystem.lock()->GetApplication()->GetResources()->LoadResource<Texture>("test.png");
	}

	bool UiComponent::CheckForMouseHover()
	{
		/*if (InputManager::mouseX > rect.x && InputManager::mouseX < rect.x + rect.w && InputManager::mouseY > rect.y && InputManager::mouseY < rect.y + rect.h) removed for rewrite.
		{
			return true;
		}*/

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
		rect.position = glm::vec2(0, 0);
		rect.scale = glm::vec2(1, 1);

		std::shared_ptr<UiSystem> ui = parentSystem.lock();
		ui->GetApplication()->uiShader->UseShader();
		ui->GetApplication()->uiShader->BindMatrix("u_Orthographic", ui->GetApplication()->GetScreen()->GetOrthographic());
		ui->GetApplication()->uiShader->BindMatrix("u_Model", rect.GetScreenPos());
		if (texture)
		{
			glBindTexture(GL_TEXTURE_2D, texture->textureID);
		}
		glBindVertexArray(uiQuad->vaoID);
		glDrawArrays(GL_TRIANGLES, 0, uiQuad->drawCount);
		glBindVertexArray(0);
		glUseProgram(0);

		std::cout << "Rendering ui element" << std::endl;
	}
}