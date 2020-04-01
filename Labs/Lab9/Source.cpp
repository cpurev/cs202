//Lab9 - Source.cpp
//Chuluunbat Purev
//2020-4-1
//Uses of static

#include <iostream>

class staticClass {
public:
	staticClass() {
	}
	void count() {
		++_count;
		std::cout << __FUNCTION__ << " " << _count << std::endl;

	}

	static void resetCount() {
		_count = 0;
		std::cout << __FUNCTION__ << " " << _count << std::endl;
	}
private:
	static int _count;
};

int staticClass::_count = 5;

void staticLocal() {
	static int count;

	std::cout << "Static variable is now " << count << std::endl;

	++count;
}

int main() {
		
	staticLocal();
	staticLocal();
	staticLocal();

	staticClass a;
	a.count();
	a.count();
	a.count();

	a.resetCount();
	a.count();
	a.count();

	return 1;
}