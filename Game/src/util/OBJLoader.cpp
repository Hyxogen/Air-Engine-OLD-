#include "OBJLoader.h"

namespace engine { namespace utility {

	geometry::Mesh* loadOBJModel(char* path) {
		using namespace math;
		using namespace geometry;

		std::vector<GLfloat> vertices, uvs ,normals, temp_normals;
		std::vector<Vector2f> temp_uvs;
		std::vector<GLuint> indices;
		std::vector<std::string> lines = IO::readFileLines(path);
		
		for (int i = 0; i < lines.size(); i++) {
			std::vector<std::string> splitted_line = split(&lines[i], ' ');

			if (splitted_line[0] == "v") {
				vertices.push_back(std::stof(splitted_line[1]));
				vertices.push_back(std::stof(splitted_line[2]));
				vertices.push_back(std::stof(splitted_line[3]));
			} else if (splitted_line[0] == "vt") {
				temp_uvs.push_back(Vector2f(std::stof(splitted_line[1]), std::stof(splitted_line[2])));
			} else if (splitted_line[0] == "vn") {
				temp_normals.push_back(std::stof(splitted_line[1]));
				temp_normals.push_back(std::stof(splitted_line[2]));
				temp_normals.push_back(std::stof(splitted_line[3]));
			} else if (splitted_line[0] == "f") {
				std::string line = ((splitted_line[1] + "/") + splitted_line[2] + "/") + splitted_line[3];
				std::vector<std::string> indices_format = split(&line, '/');

				for (int a = 0; a < 9; a += 3) {
					indices.push_back(std::stoi(indices_format[a]) - 1);
					
					Vector2f currentUV = temp_uvs[std::stoi(indices_format[a + 1]) - 1];

					uvs.push_back(currentUV.x);
					uvs.push_back(currentUV.y);
					//std::cout << "UV Cooridinate1 " << temp_uvs[ a + 1] << std::endl;
					//std::cout << "UV Cooridinate[] " << temp_uvs[a * 2 + 1]  << std::endl;


					//TODO checken welke uvs in welke indice worden geladen

					normals.push_back(temp_normals[a + 2]);
					normals.push_back(temp_normals[a + 2]);
					normals.push_back(temp_normals[a + 2]);
					//TODO Correct normals
				}

			}
		}

		return new Mesh(vertices, uvs, indices);
	}

}}