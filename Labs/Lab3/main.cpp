//main.cpp
//2020-1-30
//Chuluunbat Purev
//unique and shared pointers

#include "cats.hpp"
#include <catch.hpp>

class Vector3f {
public:
	Vector3f() {
		x = 0; y = 0; z = 0;
	}
	float x, y, z;
};

bool operator==(const Vector3f& a, const Vector3f& b) {
	return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}
bool operator!=(const Vector3f& a, const Vector3f& b) {
	return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}


TEST_CASE("Vector tests", "Vector3f") {

	Vector3f a;
	auto b = a;

	REQUIRE(a == b);
}

//int main() {
//
//	std::cout << "Created Steven\n";
//	auto* cats = new CAT("Steven");
//	std::cout << cats->getCats() << " " << cats << std::endl;
//	delete cats;
//
//	std::cout << "\nUnique pointers!\n";
//
//
//	std::cout << "Created CAT\n"; 
//	auto up = std::make_unique<CAT>();
//	std::cout << up->getCats() << " " << up << std::endl;
//
//
//	std::cout << "Moved CAT\n"; 
//	auto tp = std::move(up);
//	std::cout << tp->getCats() << " " << tp << std::endl; 
//
//
//	std::cout << "\nShared pointers!\n";
//
//	std::cout << "Created shared\n";
//	auto sp = std::make_shared<CAT>("shared");
//	std::cout << sp->getCats() << " " << sp << std::endl;
//
//	std::cout << "Created another shared\n"; 
//	auto asp = sp;
//	std::cout << asp->getCats() << " " << asp << std::endl; 
//
//	std::cout << "Cheesecake\n";
//
//	return 1;
//}