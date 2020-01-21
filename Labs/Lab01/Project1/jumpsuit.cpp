//jumpsuit.cpp
//2020-1-21
//Chuluunbat Purev
//Flow of control

#include <iostream>
#include <string>

int jumpSuit(const std::string& a) {

	if (a.compare("jumpsuit") == 0)
		return 1;
	else
		return 0;
}

int main() {

	std::string a;
	std::getline(std::cin, a);

	switch (jumpSuit(a)) {

	case 1: std::cout << "Jumpsuit" << std::endl; break;

	case 0: std::cout << "not jumpsuit" << std::endl; break;

	}

	std::cout << "The letters: " << std::endl;

	for (auto x : a) 
		std::cout << x << "  ";

	std::cout << std::endl;

	std::cout << "The ASCII numbers: " << std::endl;

	int n = a.length();
	int i = 0;
	char c;

	do {
		c = a[i];

		std::cout << c + 0 << "   ";

		i++;
	} while (i<n);

	return 1;
}