#pragma once

#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <FreeImage.h>
#include <sys/stat.h>

namespace engine {
	namespace graphics {

		class Texture {

			GLuint textureID;
			unsigned char* data;

			inline static bool exists(char* path) {
				struct stat buffer;
				return (stat(path, &buffer) == 0);
			}
		public:
			Texture();

			~Texture();

			Texture(char* path);

			inline GLuint getTextureID() const { return textureID; }
		};

	}
}