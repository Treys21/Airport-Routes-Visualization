#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>


std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;
	std::string temp;

	if (text.is_open()) {
		while (std::getline(text, temp)) {
        	if(temp.size() > 0)
            	out.push_back(temp);
    	}
    	text.close();
	}

	return out;
} 
