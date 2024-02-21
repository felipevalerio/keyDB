#include <iostream>
#include <fstream>
#include <string>
#include <map>


void add(std::map<std::string, std::string>& Coins, std::string key, std::string value) {
	
	Coins.emplace(key, value);

	try {
		std::ofstream binaryOutput("db_file/db.bin", std::ios::binary);

		binaryOutput.write(reinterpret_cast<const char*>(&Coins), sizeof(Coins));
		binaryOutput.close();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
}


void get_all() {

	std::string key;
	std::string value;
	std::map<std::string, std::string>Coins;
	std::ifstream inputFile("db_file/db.txt");


	while(inputFile >> key >> value)
		Coins[key] = value;

	for (const auto& [key, value] : Coins)
        std::cout << '[' << key << "] => " << value << "; " << "\n" << std::endl;
}


int main() {

	int choice = 0;
	std::string key;
	std::string value;
	std::map<std::string, std::string> Coins;


	while (choice != 9) {

		std::cout 
		<< 	"1)Insert" << "\n" 
		<< 	"2)List values" << "\n" 
		<< 	"9)Exit" << "\n" 
		<< std::endl;

		std::cin >> choice;

		switch (choice) {

		case 1:
			std::cout << "Insira a chave" << std::endl;
			std::cin >> key;
			std::cout << "\n" << std::endl;

			std::cout << "Insira o valor" << std::endl;
			std::cin >> value;
			std::cout << "\n" << std::endl;


			add(Coins, key, value);
			break;
		case 2:
			
			get_all();
			break;
		}
	}

	return 0;
}