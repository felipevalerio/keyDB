#include <map>
#include <string>
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void put(std::map<std::string, std::string>, std::string, std::string);

void get_all(std::map<std::string, std::string>);

void del(std::string, std::map<std::string, std::string>);

#endif