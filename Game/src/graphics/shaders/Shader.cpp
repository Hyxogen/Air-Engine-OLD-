#include "Shader.h"

namespace engine {
	namespace graphics {

		Shader::Shader(char* vertexShader, char* fragmentShader) {
			programID = glCreateProgram();

			GLuint vertexShaderID = compileShader(vertexShader, GL_VERTEX_SHADER);
			GLuint fragmentShaderID = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

			glAttachShader(programID, vertexShaderID);
			glAttachShader(programID, fragmentShaderID);
			
			glLinkProgram(programID);
			
			glValidateProgram(programID);
		}

		Shader::~Shader() {
			glDetachShader(programID, vertexShaderID);
			glDetachShader(programID, fragmentShaderID);

			glDeleteShader(vertexShaderID);
			glDeleteShader(fragmentShaderID);

			glDeleteShader(vertexShaderID);
			glDeleteShader(fragmentShaderID);
			glDeleteProgram(programID);
		}

		GLuint Shader::compileShader(char* source, GLenum type) {
			GLuint shader = glCreateShader(type);

			glShaderSource(shader, 1, &source, 0);
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			std::cout << isCompiled << std::endl;
			if (isCompiled == GL_FALSE) {
				std::cout << "Error" << std::endl;
				GLint maxLength = 9999;

				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				std::cout << "An error occured while trying to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << "shader \n" << &infoLog[0] << "\n" << std::endl;

				glDeleteShader(shader);
			}
			return shader;
		}

		void Shader::loadUniformMat4f(char* name, math::Matrix4f matrix) {
			GLuint location = getUniformLocation(name);
			glUniformMatrix4fv(location, 1, GL_FALSE, matrix.elements);
		}

		void Shader::loadUniformTexture(char* name, unsigned short bankID) {
			glUniform1i(getUniformLocation(name), bankID);
		}

		void Shader::bind() {
			glUseProgram(this->programID);
		}

		void Shader::unBind() {
			glUseProgram(0);
		}

		GLuint Shader::getUniformLocation(char* name) {
			if (uniform_locations.find(name) == uniform_locations.end()) {
				uniform_locations.emplace(name, glGetUniformLocation(this->programID, name));
			}
			return uniform_locations[name];
		}
	}
}