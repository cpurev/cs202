//lowerCase.cpp
//2020-2-2
//Chuluunbat Purev
//to all lower case

#include <iostream>

int main() {

	//Its const so we canat modify this
	const char* c = "HeLlO WoRld!";

	//Lenght of the c
	for (auto i = 0; i < strlen(c); i++) {
		//ASCII code for upper case letters
		if (c[i] > 65 && c[i] < 90)
			//Adding 32 lowers the cases to its repecting letters
			std::cout << (char)(c[i] + 32);
		else
			//if its lower case or any other letter
			std::cout << c[i];
	}
	return 1;
}