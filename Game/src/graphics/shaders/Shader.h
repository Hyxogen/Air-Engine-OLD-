#pragma once

#include <GL\glew.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "..\..\math\Matrix4f.h"

namespace engine { namespace graphics {

		class Shader {
			//TODO temporary uniform location saving
			GLuint programID, vertexShaderID, fragmentShaderID;
			GLuint compileShader(char* source, GLenum type);
			std::unordered_map<char*, GLuint> uniform_locations;
		public:
			Shader(char* vertexShader, char* fragmentShader);

			~Shader();

			void loadUniformMat4f(char* name, math::Matrix4f matrix);

			void loadUnifromMat4fa(char* name, math::Matrix4f matrices[], unsigned int size);

			void loadUnifromMat4fa(char* name, std::vector<math::Matrix4f> matrices);

			void loadUniformTexture(char* name, unsigned short bankIndex);

			void bind();

			void unBind();
		private:
			GLuint getUniformLocation(char* name);
		};
}}