//Souce.cpp
//Chuluunbat Purev
//2020-4-17
//Testing template classes

#include "Wrapper.hpp"

int main(void) {

	Wrapper<int> w{ 2 };
	Wrapper<std::string>  s{ "Hello world!" };

	std::cout << w << " " << s << std::endl;

	return 0;
}