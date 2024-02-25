#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "storage.h"

using namespace storage;

void storage::put(std::map<std::string, std::string>& Coins, std::string key, std::string value) {
	
	Coins.emplace(key, value);

	try {
		std::ofstream binaryOutput("/db_file/db.bin", std::ios::binary);

		binaryOutput.write(reinterpret_cast<const char*>(&Coins), sizeof(Coins));
		binaryOutput.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}


void storage::el(std::string key, std::map<std::string, std::string>& Coins) {

	try {
		std::ifstream binaryInput("/db_file/db.bin", std::ios::binary);

		binaryInput.read(reinterpret_cast<char*>(&Coins), sizeof(Coins));
		binaryInput.close();

		Coins.erase(key);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}


void storage::get_all(std::map<std::string, std::string>& Coins) {

	try {
		std::ifstream binaryInput("/db_file/db.bin", std::ios::binary);

		binaryInput.read(reinterpret_cast<char*>(&Coins), sizeof(Coins));
		binaryInput.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (const auto& [key, value] : Coins)
        std::cout << '[' << key << "] => " << value << "; " << "\n" << std::endl;
}