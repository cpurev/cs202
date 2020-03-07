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

	//while (cave.play()) {
	//	std::cout << "You are in room: " << cave.getCurrentRoom() << '\n';
	//	switch (cave.hazardHint())
	//	{
	//	case -1: std::cout << "A pit! Luckily bats were there too! They carried you to random room!\n";
	//		cave.gotoRoom(-1); break;
	//	case 0: std::cout << "Bats they carried you to random room!\n"; cave.gotoRoom(-1); break;
	//	case 1: std::cout << "You fell in a pit!"; break;
	//	case 2: break;
	//	default:
	//		break;
	//	}

	//}

	return 1;
}