#include "Texture.h"
#include <iostream>

namespace engine { namespace graphics {

	Texture::Texture() {
		printf("It is discouraged to use this constructor");
	}

	Texture::Texture(char* path) {
		unsigned char header[54];
		unsigned int dataPos;
		unsigned int width, height;
		unsigned int imageSize;
		FILE* file;

		fopen_s(&file, path, "rb");
		if (file == 0) {
			std::cout << "File " << path << " could not be opened!" << std::endl;
			return;
		}

		if (fread(header, 1, 54, file) != 54) {
			std::cout << "Not a correct BMP file!" << std::endl;
			return;
		}

		if (header[0] != 'B' || header[1] != 'M') {
			std::cout << "Not a correct BMP file!" << std::endl;
			return;
		}


		dataPos = *(int *)& (header[0x0A]);
		imageSize = *(int *)& (header[0x22]);
		width = *(int *)& (header[0x12]);
		height = *(int *)& (header[0x16]);
		
		if (imageSize == 0)    imageSize = width*height * 3;
		if (dataPos == 0)      dataPos = 54;

		//data = (unsigned char*)malloc(width * height * sizeof(int));
		data = new unsigned char[imageSize];

		fread(data, width * height * sizeof(int), 1, file);
 		fclose(file);
		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	}

	Texture::~Texture() {
		glDeleteTextures(1, &textureID);
		//delete data;
	}

}}