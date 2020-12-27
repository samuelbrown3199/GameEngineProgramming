#include "MeshRenderer.h"

#include "Application.h"
#include "Camera.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "ResourceManager.h"

namespace myengine
{
	void MeshRenderer::onRender()
	{
		if (shader)
		{
			shader->UseShader();
			shader->BindMatrix("u_Projection", GetEntity()->GetApplication()->GetScreen()->GetPerspective());
			shader->BindMatrix("u_Model", GetEntity()->GetComponent<Transform>()->GetModelMatrix());
			shader->BindMatrix("u_View", GetEntity()->GetApplication()->camera->view);
			if (texture)
			{
				glBindTexture(GL_TEXTURE_2D, texture->textureID);
			}
			glBindVertexArray(model->vaoID);
			glDrawArrays(GL_TRIANGLES, 0, model->drawCount);
			glBindVertexArray(0);
			glUseProgram(0);
		}
	}

	void MeshRenderer::SetModel(std::string modelPath)
	{
		model = GetResources()->LoadResource<Model>(modelPath);
	}

	void MeshRenderer::SetShader(std::shared_ptr<Shader>sha)
	{
		shader = sha;
	}

	void MeshRenderer::SetTexture(std::shared_ptr <Texture> tex)
	{
		texture = tex;
	}
}