//Souce.cpp
//Chuluunbat Purev
//2020-4-23
//Two STL algorithms example

#include <algorithm>
#include <iostream>
#include <random>
#include <string>

int main(void) {

	//Gets a random element from the given "sample"
	std::string in = "aeiou", out;
	//std::sample(starting of sample, end of sample, output where the result is written, number of results, random device)
	std::sample(in.begin(), in.end(), std::back_inserter(out), 1, std::mt19937{ std::random_device{}()});
	std::cout << "A random VOWEL: " << out << std::endl;

	//Transforms given range and puts it into different range
	//In this example "tranformed" every whitespace into newline
	//as defined in the lambda function
	//Resulting in line of words
	std::string str("A sentence is a set of words that is complete in itself, typically containing a subject and predicate, conveying a statement, question, exclamation, or command, and consisting of a main clause and sometimes one or more subordinate clauses.");
	std::string strO;
	std::transform(str.begin(), str.end(), std::back_inserter(strO), 
		[](unsigned char c) -> unsigned char { return (c == ' ') ? '\n' : c; });
	std::cout << strO;

	return 0;
}