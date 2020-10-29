#include "TriangleRenderer.h"
#include "Entity.h"
#include "Application.h"
#include "Screen.h"
#include "Transform.h"
#include "Shader.h"

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
	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	shader = std::make_shared<Shader>("vertex.vs", "fragment.fs");
	shader->BindAttributeLocation(0, "in_Position");
}

void TriangleRenderer::onRender()
{
	shader->UseShader();
	shader->BindMatrix("u_Projection", getEntity()->getApplication()->GetScreen()->GetPerspective());
	shader->BindMatrix("u_Model", getEntity()->GetComponent<Transform>()->GetModelMatrix());
	//shader->BindMatrix("u_Model", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10)));

	glBindVertexArray(vaoId);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glUseProgram(0);
}