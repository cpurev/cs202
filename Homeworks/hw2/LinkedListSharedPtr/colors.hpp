//colors.hpp
//2020-2-2
//Chuluunbat Purev
//Colors with list type shared_ptr

#ifndef COLORS_LINKED_HPP
#define COLORS_LINKED_HPP
#include <list>
#include <iostream>

struct Colors {
	std::string str;
};

void addQueue(std::list<std::shared_ptr<Colors>>& list, const Colors& val);

void popQueue(std::list<std::shared_ptr<Colors>>& list);

void pushStack(std::list<std::shared_ptr<Colors>>& list, const Colors& val);

void popStack(std::list<std::shared_ptr<Colors>>& list);

void insert(std::list<std::shared_ptr<Colors>>& list, const Colors& val, std::list<std::shared_ptr<Colors>>::iterator n);
bool find(const std::list<std::shared_ptr<Colors>>& list, const Colors& val);

#endif // !COLORS_LINKED_HPP

