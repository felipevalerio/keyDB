#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "storage.hpp"


void put(std::map<std::string, std::string>& Map, std::string key, std::string value) {
	
	Map.emplace(key, value);

	try {
		std::ofstream binaryOutput("/db_file/db.bin", std::ios::binary);

		binaryOutput.write(reinterpret_cast<const char*>(&Map), sizeof(Map));
		binaryOutput.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}


void get_all(std::map<std::string, std::string>& Map) {

	try {
		std::ifstream binaryInput("/db_file/db.bin", std::ios::binary);

		binaryInput.read(reinterpret_cast<char*>(&Map), sizeof(Map));
		binaryInput.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (const auto& [key, value] : Map)
        std::cout << '[' << key << "] => " << value << "; " << "\n" << std::endl;
}


void del(std::string key, std::map<std::string, std::string>& Map) {

	try {
		std::ifstream binaryInput("/db_file/db.bin", std::ios::binary);

		binaryInput.read(reinterpret_cast<char*>(&Map), sizeof(Map));
		binaryInput.close();

		Map.erase(key);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}
