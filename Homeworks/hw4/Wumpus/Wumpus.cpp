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

	while (true) {
		if (cave.playerState != true || cave.wumpState != true)
			break;

		std::cout << "You are in room: " << cave.getCurrentRoom() << '\n';
		switch (cave.hazard())
		{
		case -1: std::cout << "A pit! Luckily bats were there too! They carried you to random room!\n";
			cave.gotoRoom(-1); continue;
		case 0: std::cout << "Bats! They carried you to random room!\n"; cave.gotoRoom(-1); continue;
		case 1: std::cout << "You fell in a pit!"; cave.playerState = false; continue;
		case 2: break;
		default:
			break;
		}

		switch (cave.hazardHint())
		{
		case 0: std::cout << "Bats nearby...\n"; break;
		case 1: std::cout << "You feel a draft...\n"; break;
		case 2: std::cout << "You smell a horrid stench..\n"; break;
		default:
			break;
		}

		std::cout << "Tunnels lead to: " + cave.getAdjRooms();

		char c;
		int i = 0;
		std::cout << "Shoot or Move? (S-M)"; std::cin >> c;

		if (c == 'M' || c == 'm') {
			while (cave.playerMove(i)) {
				std::cout << "Where to? "; std::cin >> i;
			}
			continue;
		}

		if (c == 'S' || c == 's') {
			std::cout << "You have #" << cave.arrows << "arrows";
			std::cout << "Enter a room to shoot at: "; std::cin >> i;
			cave.playerShoot(i);
			continue;
		}


	}

	if (cave.playerState == false)
		std::cout << "Wumpus ate you! Game Over!";

	if (!cave.wumpState)
		std::cout << "You killed the wumpus! You had " << cave.arrows << " arrows left!";

	return 1;
}