#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
class CAT {
public:
	CAT();
	CAT(const CAT &c);
	CAT(const char* c);
	const char* getCats();
	~CAT();
private:
	const char* _c;
};

#endif // !CAT_HPP
