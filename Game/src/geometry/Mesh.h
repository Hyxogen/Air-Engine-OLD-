#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "../graphics/Texture.h"

namespace engine { namespace geometry {

	class Mesh {
		
		unsigned int vertexCount, indicesCount;

		//TODO: Create material class that contains the texture
		graphics::Texture* texture = 0;

		GLuint vaoID = 0, iboID = 0;
		std::vector<GLuint> vbos;

	public:
		Mesh(std::vector<GLfloat>& vertices,std::vector<GLfloat> uvs,std::vector<GLuint>& indices,
			 graphics::Texture* texture);

		~Mesh();

		inline GLuint getVaoID() const { return vaoID; }
		inline GLuint getIboID() const { return iboID; }
		inline graphics::Texture* getTexture() const { return texture; }
		inline unsigned int getVertexCount() const { return vertexCount; }
		inline unsigned int getIndicesCount() const { return indicesCount; }
	private:
		void createAndBindIBO(const GLuint data[],const unsigned int size);
		void createAndBindVBO(const GLuint& index,GLfloat data[], const unsigned int size, unsigned short dimensions);
	};

}}