//colors.hpp
//2020-2-2
//Chuluunbat Purev
//Colors with list type shared_ptr

#ifndef COLORS_LINKED_HPP
#define COLORS_LINKED_HPP
#include <list>
#include <iostream>

struct Value {
	std::string str;
};

void addQueue(std::list<std::shared_ptr<Value>>& list, const Value& val);

void popQueue(std::list<std::shared_ptr<Value>>& list);

void pushStack(std::list<std::shared_ptr<Value>>& list, const Value& val);

void popStack(std::list<std::shared_ptr<Value>>& list);

void insert(std::list<std::shared_ptr<Value>>& list, const Value& val, std::list<std::shared_ptr<Value>>::iterator n);
bool find(const std::list<std::shared_ptr<Value>>& list, const Value& val);

#endif // !COLORS_LINKED_HPP

