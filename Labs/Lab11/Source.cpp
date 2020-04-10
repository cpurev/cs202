//Source.cpp
//Chuluunbat Purev
//2020-4-9
//Inheritance lab

#include <iostream>

class Base {
public:
	Base() {
		std::cout << "Base construction with 0" << std::endl;
	}
	Base(int a) : _a(a) {
		std::cout << "Base construction with " << a << std::endl;
	}
	~Base() {
		std::cout << "~Base deconstruction with " << _a << std::endl;
	}
private:
	int _a = 0;
};

class Derived : public Base{
public:
	Derived() : Base(10), _name("Turbo"){
		std::cout << "Construction of Derived named " << _name << std::endl;
	}
	Derived(int a, std::string str) : Base(a), _name(str) {
		std::cout << "Construction of Derived named " << _name << std::endl;
	}
	Derived(int a) : Base(a) {
		std::cout << "Construction of Derived named " << _name << std::endl;
	}
	~Derived() {
		std::cout << "Deconstruction of Derived named " << _name << std::endl;
	}
private:
	std::string _name;
};


int main(void) {

	{Base b; }
	std::cout << std::endl;

	{Base b{ 13 }; }
	std::cout << std::endl;

	{Derived d; }
	std::cout << std::endl;

	{Derived d{ 16,"Eliza" }; }
	std::cout << std::endl;

	Derived d{ 3 };


	return 0;
}