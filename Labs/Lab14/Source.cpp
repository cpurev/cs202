//Souce.cpp
//Chuluunbat Purev
//2020-4-23
//Function tempaltes

#include <iostream>

template <typename T>
T twice(const T& t) {
	return t + t;
}

std::string twice(const char* t) {
	return twice(std::string(t));
}

int main(void) {
	
	std::cout << twice(2) << std::endl;
	std::cout << twice(2.3) << std::endl;
	std::cout << twice(std::string("Hello")) << std::endl;
	

	std::cout << twice("World") << std::endl;

	return 0;
}