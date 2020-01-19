//temperature.cpp
//2020-1-18
//Chuluunbat Purev
//Fahrenheit to Celsius with inputs from command line

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

//Uses stod
double c_ctof(const char* str) {

	double d = 999;

	if(d = std::stod(str))
		d = (d - 32) * (5.0 / 9);

	return d;
}

int main(int argc, char* argv[]) {

	//Default value of string to avoid null errors
	std::string str = "NULL";

	//Check to aboid null error
	if(argv[1] != NULL)
		str = argv[1];
	if (argv[2] == NULL)
		return 0;

	//Function callers
	if (str == "--ftoc")
		std::cout << "Celsius: " << cpp_ftoc(argv[2]) << std::endl;

	else if (str == "--ctof")
		std::cout << "Celsius" << c_ctof(argv[2]) << std::endl;

	return 1;
}