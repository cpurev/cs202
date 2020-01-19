//temperature.cpp
//2020-1-18
//Chuluunbat Purev
//Fahrenheit to Celsius

#include <iostream>
#include <string>
#include <sstream>

//Uses stringstream
double cpp_ftoc(const char* str) {

	std::istringstream iss;
	iss.str(str);
	double d = 999;

	if (iss >> d)
		d = (d - 32) * (5.0 / 9);

	return d;
}

//Used stod
double c_ctof(const char* str) {

	double d = 999;

	d = std::stod(str);

	d = (d - 32) * (5.0 / 9);

	return d;
}

int main(int argc, char* argv[]) {

	for (auto i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}
	std::string str = "NULL";


	if(argv[1] != NULL)
		str = argv[1];

	if (argv[2] == NULL)
		return 0;

	if (str == "--ftoc")
		std::cout << cpp_ftoc(argv[2]) << std::endl;

	else if (str == "--ctof")
		std::cout << c_ctof(argv[2]) << std::endl;
	return 1;
}