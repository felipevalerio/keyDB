#include <iostream>
#include <string>
#include <map>


void add(std::map<std::string, std::string>& Coins, std::string key, std::string value) {

	Coins.insert(std::make_pair(key, value));
}


void get_all(std::map<std::string, std::string>& Coins) {

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
		<< 	"9)Sair" << "\n" 
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
			
			get_all(Coins);
			break;
		}
	}


	return 0;
}