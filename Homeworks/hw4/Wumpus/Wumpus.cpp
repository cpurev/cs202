//Wumpus.cpp
//Chuluunbat Purev
//2020-03-04
//Hunt the Wumpus Game

#include "wumpusCave.hpp"

int main(void) {
	//Init rooms
	Cave cave;

	//Init bat, wump, pit rooms randomly
	cave.initRooms();

	//Connect the rooms randomly
	cave.connectRooms();

	//Debugging print to caveLayout.txt file
	cave.printRooms();

	while (true) {
		//State checker for the game results
		if (!cave.playerState || !cave.wumpState)
			break;

		//Another state checker
		if (cave.arrows == 0) {
			std::cout << "You are out of arrows!\n";
			cave.playerState = false;
			break;
		}

		//Current room alert
		std::cout << "You are in room: " << cave.getCurrentRoom() << '\n';

		//Current room hazards
		switch (cave.hazard())
		{
		case -1: std::cout << "A pit! Luckily bats were there too! "
								<< "They carried you to random room!\n";
			cave.gotoRoom(-1); continue;
		case 0: std::cout << "Bats! They carried you to random room!\n"; 
			cave.gotoRoom(-1); continue;
		case 1: std::cout << "You fell in a pit!\n"; 
			cave.playerState = false; continue;
		case 2: std::cout << "You found wumpus!\n"; 
			cave.playerState = false; continue;
		default:
			break;
		}

		//Adjacent room hazard printer
		cave.hazardHint();

		//Adjacent room sprinter
		std::cout << "Tunnels lead to: " + cave.getAdjRooms();

		char c;
		int i = 0;
		std::cout << "Shoot or Move? (S-M): "; std::cin >> c;

		//Move the player and restart
		if (c == 'M' || c == 'm') {
			 do{
				std::cout << "Where to? "; std::cin >> i;
			}while (cave.playerMove(i));

			continue;
		}

		//Shoot
		//From the results checks if to restart or to end game
		if (c == 'S' || c == 's') {
			std::cout << "You have #" << cave.arrows << " arrows\n";
			std::cout << "Enter a room to shoot at: "; std::cin >> i;
			--cave.arrows;
			cave.playerShoot(i);
			continue;
		}


	}

	//PLayer loss
	if (cave.playerState == false)
		std::cout << "Game Over!";

	//PLayer win
	if (!cave.wumpState)
		std::cout << "You killed the wumpus! You had " 
					<< cave.arrows << " arrows left!";

	return 1;
}