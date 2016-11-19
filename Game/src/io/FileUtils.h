#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

namespace engine { namespace IO {

	char* readFile(char* path);

	std::vector<std::string> readFileLines(char* path);

}}