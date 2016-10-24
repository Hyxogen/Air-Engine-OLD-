#pragma once

#include <GL\glew.h>
#include <iostream>
#include <vector>
#include "..\..\math\Matrix4f.h"

namespace engine { namespace graphics {

	class Shader {

		GLuint programID, vertexShaderID, fragmentShaderID;
		
		GLuint compileShader(char* source, GLenum type);

	public:
			Shader(char* vertexShader, char* fragmentShader);
		
			~Shader();

			void loadUniformMat4f(char* name, math::Matrix4f matrix);

			void bind();

			void unBind();
	};

}}