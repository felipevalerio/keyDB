#include <iostream>
#include <string>
#include <map>


void insert(std::string key, std::string value) {

	std::map<std::string, std::string> Coins;
	Coins.insert(make_pair(key, value));

}

int main() {

	std::string key;
	std::string value;

	std::cout << "Insira a nome da criptomoeada" << "\n\n" << std::endl;
	std::cin >> key;

	std::cout << "Insira o valor da criptomoeda" << "\n\n" << std::endl;
	std::cin >> value;

	insert(key, value);

	return 0;
}