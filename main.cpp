#include <iostream>
#include <string>
#include <map>


void add(const std::map<std::string, std::string>& Coins, std::string key, std::string value) {

	Coins.insert(make_pair(key, value));

}

void get_all(const std::map<std::string, std::string>& Coins) {

	for (const auto& [key, value] : Coins)
        std::cout << '[' << key << "] = " << value << "; ";

}


int main() {

	std::string key;
	std::string value;
	std::map<std::string, std::string> Coins;

	std::cout << "Insira a chave" << "\n\n" << std::endl;
	std::cin >> key;

	std::cout << "Insira o valor" << "\n\n" << std::endl;
	std::cin >> value;

	add(Coins, key, value);

	return 0;
}