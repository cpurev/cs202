//binaryFile.cpp
//2020-2-6
//Chuluunbat Purev
//Binary file reading and writing

#include <iostream>
#include <fstream>
#include <string>

int main() {
/*
	std::ofstream of("test.txt");

	const char* c = "What";

	of.write(reinterpret_cast<const char*>(c), sizeof(c));*/
	
	std::ifstream in("data.dat", std::ios_base::binary);

	if (!in) {
		std::cout << "Read error!";
		return 0;
	}

	int a = 0, count = 0;
	double avg = 0, sum = 0;

	std::cout << "All the numbers:\n";
	while (in.read(reinterpret_cast<char*>(&a), sizeof(a))) {
		std::cout << a << "\n";
		sum += a;
		++count;
	}

	std::cout << "Total number of numbers: " << count << "\n";
	std::cout << "Sum of the numbers: " << sum << "\n";

	avg = sum / count;

	std::cout << "Avarage of the numbers: " << avg << "\n";


	return 1;
}