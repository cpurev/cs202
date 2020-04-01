//Lab9 - Source.cpp
//Chuluunbat Purev
//2020-4-1
//Uses of static

#include <iostream>

class staticClass {
public:
	staticClass() {
		std::cout << __FUNCTION__ << " " << _count << std::endl;
		++_count;
	}
	void publicCount() {
		std::cout << __FUNCTION__ << " " << _publicCount << std::endl;
		++_publicCount;

	}
	static int _publicCount;
private:
	static int _count;
};
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
	a.publicCount();

	return 1;
}