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
	/**
	*Stores glsl shader information as an opengl shader program.
	*/
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
		/**
		*Takes the shader files and compiles it into a usable shader program.
		*/
		void SetupShader(const GLchar* vertexSource, const GLchar* fragmentSource);
		/**
		*Sets the state of opengl to use this shader program.
		*/
		void UseShader();	
		/**
		*Binds a matrix 4x4 to the shader program to the parameter location.
		*/
		void BindMatrix(std::string location, glm::mat4 matrix);

	protected:

	};
}

