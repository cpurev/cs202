//Wumpus.cpp
//Chuluunbat Purev
//2020-03-04
//Hunt the Wumpus Game

#include "wumpusCave.hpp"

int main(void) {

	Cave cave;

	cave.initRooms();

	cave.connectRooms();

	cave.printRooms();

	while (cave.play()) {
		std::cout << "You are in room: " << cave.getCurrentRoom() << '\n';
	}

	return 1;
}