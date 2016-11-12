#include "StringUtils.h"

namespace engine { namespace utility {

	std::vector<std::string> split(std::string* string, char delimeter) {
		std::vector<std::string> splitted_string;
		std::stringstream* stringstream = new std::stringstream();
		stringstream->str(*string);

		std::string splitted;

		while (std::getline(*stringstream, splitted, delimeter)) {
			splitted_string.push_back(splitted);
		}
		delete stringstream;
		return splitted_string;
	}

}}