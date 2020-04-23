//Souce.cpp
//Chuluunbat Purev
//2020-4-23
//Function tempaltes

#include <iostream>

template <typename T>
T twice(const T& t) {
	return t + t;
}

int main(void) {
	
	std::cout << twice(2) << std::endl;
	std::cout << twice(2.3) << std::endl;
	std::cout << twice(std::string("Hello")) << std::endl;
	
	return 0;
}