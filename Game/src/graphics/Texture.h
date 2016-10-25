#pragma once

#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <FreeImage.h>

namespace engine {
	namespace graphics {

		class Texture {

			GLuint textureID;
			unsigned char* data;

		public:
			Texture();

			~Texture();

			Texture(char* path);

			inline GLuint getTextureID() const { return textureID; }
		};

	}
}