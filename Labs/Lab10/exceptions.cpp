//Lab10 - exceptions.cpp
//Chuluunbat Purev
//2020-4-1
//Exception usage

#include <iostream>

class Object {
public:
	Object() {
		std::cout << "Object Constructed" << std::endl;
	}
	~Object() {
		std::cout << "Object Destructed" << std::endl;
	}
};

void functionC()
{
	//your code here
	throw std::runtime_error("functionC() threw");
}

void functionB()
{
	//your code here
	std::cout << "Starting functionB()\n";
	functionC();
	std::cout << "Ending functionB()\n";
}

void functionA()
{
	// your code here
	try{
		Object obj;
		functionB();
	}
	// your code here

	catch (const std::exception e) {
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	
	// your code here
}

int main()
{
	std::cout << "Starting main()" << std::endl;
	functionA();
	std::cout << "Ended normally." << std::endl;
	return 0;
}