#include "Texture.h"
#include <iostream>

namespace engine { namespace graphics {

	Texture::Texture() {
		printf("It is discouraged to use this constructor");
	}

		Texture::Texture(char* path) {
			FREE_IMAGE_FORMAT format = FreeImage_GetFileType(path);
			if (format == FIF_UNKNOWN)
				format = FreeImage_GetFIFFromFilename(path);
			if (!FreeImage_FIFSupportsReading(format)) {
				printf("The file format is not supported!");
				return;
			}

			FIBITMAP* bitMap = FreeImage_Load(format, path);

			const BYTE* pixels = FreeImage_GetBits(bitMap);

			unsigned int bpp = FreeImage_GetBPP(bitMap);
			GLsizei width = FreeImage_GetWidth(bitMap);
			GLsizei height = FreeImage_GetHeight(bitMap);
			GLsizei size = width * height * (bpp / 8);

			std::cout << "Bit per pixel " << bpp << std::endl;

			BYTE* result = new BYTE[size];
			memcpy(result, pixels, size);

			FreeImage_Unload(bitMap);

			glGenTextures(1, &textureID);
			glBindTexture(GL_TEXTURE_2D, textureID);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, (bpp / 8 == GL_BGR) ? GL_BGR : GL_RGB, GL_UNSIGNED_BYTE, result);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

			glBindTexture(GL_TEXTURE_2D, 0);

		}

	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
		//delete data;
	}

}}