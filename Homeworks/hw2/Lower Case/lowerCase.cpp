//lowerCase.cpp
//2020-2-2
//Chuluunbat Purev
//to all lower case

#include <iostream>

int main() {

	const char* c = "HeLlO WoRld!";
	int a = 0;

	for (auto i = 0; i < strlen(c); i++) {
		if (c[i] > 65 && c[i] < 90)
			std::cout << (char)(c[i] + 32);
		else
			std::cout << c[i];
	}
	return 1;
}