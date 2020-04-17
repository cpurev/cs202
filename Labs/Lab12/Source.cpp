//Souce.cpp
//Chuluunbat Purev
//2020-4-17
//Polymorphism

#include <iostream>

class Base {
public:
	Base() { std::cout << "Base::Base class constructor\n";  }
	virtual ~Base() { std::cout << "Base::~Base class deconstructor\n"; }
	virtual void printV() { std::cout << "Base::Virtual print\n"; }
	void print() { std::cout << "Base::Non-virtual print\n"; }
};

class Derived : public Base {
public:
	Derived() { std::cout << "Derived::Derived class constructor\n"; }
	~Derived() { std::cout << "Derived::~Derived class deconstructor\n"; }
	void printV() override { std::cout << "Derived::Virtual print\n"; }
	void print() { std::cout << "Derived::Non-virtual print\n"; }
};

int main(void) {
	//Just a base class
	{Base* ptr = new Base();
	ptr->printV();
	ptr->print();
	delete ptr; }
	std::cout << "\n----------------\n";

	//Pointer type is Base and printV is virtual so compiler knows to use it from Base
	{Base* ptr = new Derived();
	ptr->printV();
	ptr->print();
	delete ptr; }
	std::cout << "\n----------------\n";
	
	//Just a derived class
	{Derived* ptr = new Derived();
	ptr->printV();
	ptr->print();
	delete ptr; }
	std::cout << "\n----------------\n";
	
	//Just base class
	{Base b; 
	Base& ptr = b;
	ptr.printV();
	ptr.print();}
	std::cout << "\n----------------\n";
	
	//Referenced type is Base and printV is virtual so compiler knows to use it from Base
	{	Derived d;
	Base& ptr = d;
	ptr.printV();
	ptr.print(); }
	std::cout << "\n----------------\n";
	
	//Just a derived class
	{	Derived d;
	Derived& ptr = d;
	ptr.printV();
	ptr.print(); }

	return 0;
}