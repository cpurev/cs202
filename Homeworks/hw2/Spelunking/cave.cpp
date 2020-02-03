//cave.cpp
//2020-2-2
//Chuluunbat Purev
//Definition of cave.hpp

#include "cave.hpp"


int Cave::size() const {
	
	return caveRooms.size();

}

int Cave::getCurrentRoom() {
	return currentRoom + 1;
}

void Cave::gotoRoom(int room) {
	currentRoom = room - 1;

}

void Cave::gotoAdjacentRoom(int room) {
	//
}

void Cave::connect(int room1, int room2) {
	int i = 0;

	if(caveRooms[room1 - 1]->rooms[0] == nullptr)
		caveRooms[room1 - 1]->rooms[0] = caveRooms[room2 - 1];
	caveRooms[room2 - 1]->rooms[0] = caveRooms[room1 - 1];
}


void Cave::printShortDesc(int room) const {
	std::cout << caveRooms[room]->shortdesc << std::endl;

}

void Cave::printLongDesc(int room) const {
	std::cout << caveRooms[room]->longdesc << std::endl;
}

void Cave::saveRooms(std::ostream& os) const {
	for (auto x : caveRooms)
		os << x->rooms << " " << x->shortdesc << " " << x->longdesc << "\n";
}

void Cave::readRooms(std::istream& is) {

	std::string str;
	std::istringstream iss;
	int n = 0;
	int i = 0;
	CaveNode cn;
	while (std::getline(is, str)) {

		iss.str(str);


		if (!(iss >> n)) {
			if (cn.longdesc == "")
				cn.longdesc = str;
			else
				cn.shortdesc = str;
		}
		iss.clear();
		++i;
		if (i == 6) {
			CaveNodePtr ptr = std::make_shared<CaveNode>(cn);
			caveRooms.push_back(ptr);
			i = 0;
		}
	}


}