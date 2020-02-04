//colors.hpp
//2020-2-2
//Chuluunbat Purev
//Colors with list type shared_ptr

#include <list>
#include <iostream>

#ifndef COLORS_LINKED_HPP
#define COLORS_LINKED_HPP

struct Colors {
	std::string str;
};

//Add value to the end
void addQueue(std::list<std::shared_ptr<Colors>>& list, const Colors& val);

//Pop value from the front
void popQueue(std::list<std::shared_ptr<Colors>>& list);

//Add value to the end
void pushStack(std::list<std::shared_ptr<Colors>>& list, const Colors& val);

//Pop from the end 
void popStack(std::list<std::shared_ptr<Colors>>& list);

//Insert using insert method from list header
void insert(std::list<std::shared_ptr<Colors>>& list, const Colors& val, std::list<std::shared_ptr<Colors>>::iterator n);

//Custom find by just comparing strings in struct
bool find(const std::list<std::shared_ptr<Colors>>& list, const Colors& val);

//print contents
void print(std::list<std::shared_ptr<Colors>>& list);

#endif // !COLORS_LINKED_HPP

