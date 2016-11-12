#include "FileUtils.h"

namespace engine { namespace IO {

	char* readFile(char* path) {
		FILE* file = NULL;
		
		fopen_s(&file, path, "rt");
		
		if (file == NULL) {
			std::cout << "Error file: " << path << " could not be found" << std::endl;
			return NULL;
		}
		fseek(file, 0, SEEK_END);

		unsigned long length = ftell(file);

		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, length, sizeof(char), file);

		std::cout << data << std::endl;

//		delete data;
		fclose(file);
		return data;
	}

	std::vector<std::string> readFileLines(char* path) {
		std::vector<std::string> lines(0);
		std::ifstream file(path);
		std::string line;

		while (std::getline(file, line)) {
			//std::cout << ((char*)line.c_str()) << std::endl;
			lines.push_back(line);
		}

		return lines;
	}

}}