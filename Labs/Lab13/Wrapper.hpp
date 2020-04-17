//Wrapper.hpp
//Chuluunbat Purev
//2020-4-17
//Class templates

#include <iostream>

template <typename T>
class Wrapper {
public:
	Wrapper(const T& t) : _t(t) {};
private:
	T _t;

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const Wrapper<T>& t);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Wrapper<T>& t) {
	os << t._t;
	return os;
}