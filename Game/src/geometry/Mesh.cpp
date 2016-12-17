#include "Mesh.h"

namespace engine {
	namespace geometry {

		Mesh::Mesh(std::vector<GLfloat>& vertices, std::vector<GLfloat>& uvs, 
			std::vector<GLuint>& indices) {
			this->vertexCount = vertices.size() / 3;
			this->indicesCount = indices.size();
			glGenVertexArrays(1, &vaoID);
			glBindVertexArray(vaoID);

			createAndBindIBO(&indices[0], indicesCount);
			createAndBindVBO(0, &vertices[0], vertexCount, 3);
			createAndBindVBO(1, &uvs[0], uvs.size() / 2, 2);

			glBindVertexArray(0);
		}

		Mesh::~Mesh() {
			glBindVertexArray(0);
			glDeleteVertexArrays(1, &vaoID);

			for (unsigned int i = 0; i < vbos.size(); i++)
				glDeleteBuffers(1, &vbos[i]);
		}

		void Mesh::createAndBindIBO(const GLuint data[], const unsigned int size) {
			glGenBuffers(1, &iboID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);

			glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(data), data, GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void Mesh::createAndBindVBO(const GLuint &index, GLfloat data[], const unsigned int size, unsigned short dimensions) {
			GLuint vbo;

			glGenBuffers(1, &vbo);

			vbos.push_back(vbo);

			glBindBuffer(GL_ARRAY_BUFFER, vbo);

			glBufferData(GL_ARRAY_BUFFER, size * dimensions * sizeof(data), data, GL_STATIC_DRAW);
			glVertexAttribPointer(index, dimensions, GL_FLOAT, GL_FALSE, 0, 0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
}