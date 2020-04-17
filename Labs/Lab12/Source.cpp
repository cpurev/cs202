//Souce.cpp
//Chuluunbat Purev
//2020-4-17
//Polymorphism

#include <iostream>

class Base {
	Base() { std::cout << "Base class constructor\n";  }
	~Base() { std::cout << "~Base class deconstructor\n"; }
	virtual void printV() { std::cout << "Virtual print\n"; }
	void print() { std::cout << "Non-virtual print\n"; }
};

class Derived : public Base {
	Derived() { std::cout << "Derived class constructor\n"; }
	void printV() override {

	}

	void print(){

	}
};

int main(void) {



	return 0;
}