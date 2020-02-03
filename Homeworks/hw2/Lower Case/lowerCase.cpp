//lowerCase.cpp
//2020-2-2
//Chuluunbat Purev
//to all lower case

#include <iostream>

int main() {

	const char* c = "HeLlO WoRld!";

	for (auto i = 0; i < strlen(c); i++)
		std::cout << c[i] << " ";

	return 1;
}