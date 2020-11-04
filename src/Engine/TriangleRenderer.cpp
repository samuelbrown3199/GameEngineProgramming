#include "TriangleRenderer.h"
#include "Entity.h"
#include "Application.h"
#include "ResourceManager.h"
#include "Screen.h"
#include "Transform.h"
#include "Shader.h"
#include "Texture.h"

using namespace myengine;

TriangleRenderer::TriangleRenderer()
{
}

void TriangleRenderer::onInitialize()
{
	const GLfloat positions[] =
	{
		0.0f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	GLuint positionsVboId = 0;
	// Create a new VBO on the GPU and bind it
	glGenBuffers(1, &positionsVboId);
	if (!positionsVboId)
	{
		throw std::exception();
	}
	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	// Upload a copy of the data from memory into the new VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	const GLfloat uvs[] =
	{
		0.5f, 1.0f,   // top-center corner
		0.0f, 0.0f,  // lower-left corner  
		1.0f, 0.0f,  // lower-right corner
	};

	GLuint uvVboId = 0;
	glGenBuffers(1, &uvVboId);
	if (!uvVboId)
	{
		throw std::exception();
	}
	glBindBuffer(GL_ARRAY_BUFFER, uvVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(uvs), uvs, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &vaoId);
	if (!vaoId)
	{
		throw std::exception();
	}
	glBindVertexArray(vaoId);
	// Bind the position VBO, assign it to position 0 on the bound VAO
	// and flag it to be used
	glBindBuffer(GL_ARRAY_BUFFER, positionsVboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, uvVboId);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	shader = std::make_shared<Shader>("vertex.vs", "fragment.fs");
	texture = GetResources()->LoadResource<Texture>("test.png");
	shader->BindAttributeLocation(0, "in_Position");
	shader->BindAttributeLocation(0, "in_TexCoords");
}

void TriangleRenderer::onRender()
{
	shader->UseShader();
	shader->BindMatrix("u_Projection", GetEntity()->getApplication()->GetScreen()->GetPerspective());
	shader->BindMatrix("u_Model", GetEntity()->GetComponent<Transform>()->GetModelMatrix());

	glBindTexture(GL_TEXTURE_2D, texture->textureID);
	glBindVertexArray(vaoId);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}