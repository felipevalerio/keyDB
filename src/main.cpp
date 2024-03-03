#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "storage/storage.hpp"


int main() {

	int choice = 0;
	std::string key;
	std::string value;
	std::map<std::string, std::string> Coins;


	while (choice != 9) {

		std::cout 
		<< 	"1)Insert" << "\n" 
		<< 	"2)List values" << "\n"
		<< 	"3)Delete" << "\n" 
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

			put(Coins, key, value);
			break;
		case 2:
			
			get_all(Coins);
			break;
		
		case 3:

			std::cout << "Insira a chave que deseja deletar" << std::endl;
			std::cin >> key;
			std::cout << "\n" << std::endl;

			del(key, Coins);
			break;
		}
	}

	return 0;
}