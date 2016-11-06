#include "FileUtils.h"

namespace engine { namespace utils {

	char* readFile(char* path) {
		FILE* file;
		fopen_s(&file, path, "rt");

		fseek(file, 0, SEEK_END);

		unsigned long length = ftell(file);

		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, length, sizeof(char), file);

		std::cout << data << std::endl;

		delete data;
		fclose(file);
		return NULL;
	}

}}