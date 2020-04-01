//Lab9 - Source.cpp
//Chuluunbat Purev
//2020-4-1
//Uses of static

#include <iostream>

class staticClass {
public:
	staticClass() : dummy(0){
	}
	void count() {
		++_count;
		std::cout << __FUNCTION__ << " " << _count << std::endl;

	}

	static void resetCount() {
		_count = 0;
		std::cout << __FUNCTION__ << " " << _count << std::endl;

		//Dummy is not static so this is error
		//std::cout << __FUNCTION__ << " dummy " << dummy << std::endl;
	}
private:
	int dummy;
	static int _count;
};

int staticClass::_count = 5;

//count is local static variable
void staticLocal() {
	static int count;

	std::cout << "Static variable is now " << count << std::endl;

	++count;
}

int main() {
	
	std::cout << "This is local static\n";
	//Count keeps increasing because its static
	staticLocal();
	staticLocal();
	staticLocal();

	std::cout << "\nThis is object a\n";
	//This count is only in class and only the class can use it
	//Since its static all across the same class object variable is the same
	staticClass a;
	a.count();
	a.count();
	a.count();

	std::cout << "\nThis is object b\n";
	staticClass b;
	b.count();

	//This is error because _count only is in class and its objects
	//Even though its defined globally
	//std::cout << "Count is: " << _count;

	std::cout << "\nThis is static function reseting count\n";
	//resetCount static function it will reset all the other static counts
	staticClass::resetCount();
	//b.resetCount() and a.resetCount() will do the same as above line of code
	std::cout << "\nThis is object a\n";
	a.count();
	std::cout << "\nThis is object b\n";
	b.count();

	return 1;
}