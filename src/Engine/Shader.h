#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <GL/glew.h>

#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include <string>
#include <fstream>
#include <sstream>

namespace myengine
{
	class Shader
	{
	private:

		std::string vertexCode;
		std::string fragmentCode;

		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

	public:

		GLuint programID;

		Shader(std::string vertexPath, std::string fragmentPath);
		~Shader();

		void SetupShader(const GLchar* vertexSource, const GLchar* fragmentSource);
		void UseShader();

		//void BindAttributeLocation(int index, const GLchar* name);
		void BindMatrix(std::string location, glm::mat4 matrix);

	protected:

	};
}

