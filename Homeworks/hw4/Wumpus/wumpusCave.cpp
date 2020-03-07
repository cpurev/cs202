//wumpusCave.cpp
//Chuluunbat Purev
//2020-03-04
//Wumpus Cave generator body

#include "wumpusCave.hpp"
#include <random>
#include <string>
#include <fstream>

//Random generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(1, 19);

int wumpusRoom;

Cave::Cave() : currentRoom(0), playerState(true), wumpState(true), arrows(5){
	for (auto i = 0; i < 20; i++) {
		std::string str("This is room: " + std::to_string(i));
		CaveNode cn;
		cn.desc = str;
		cn.num = i;
		caveRooms.push_back(cn);
	}
}

int Cave::getCurrentRoom() { return currentRoom; }

std::string Cave::getAdjRooms() {
	return std::to_string(caveRooms[currentRoom].rooms[0]) +  " " + std::to_string(caveRooms[currentRoom].rooms[1]) + " " + 
		std::to_string(caveRooms[currentRoom].rooms[2]) + "\n";
}

int Cave::hazard() { 
	if (caveRooms[currentRoom].bats && caveRooms[currentRoom].pit)
		return -1;
	if (caveRooms[currentRoom].bats)
		return 0;
	if (caveRooms[currentRoom].pit)
		return 1;
	if (caveRooms[currentRoom].wump)
		return 2;
	return 3;
}

int Cave::hazardHint() {

	for (auto i = 0; i < 3; i++) {
		if (caveRooms[caveRooms[currentRoom].rooms[i]].bats)
			std::cout << "	Bats nearby...\n";
		if (caveRooms[caveRooms[currentRoom].rooms[i]].pit)
			std::cout << "	I feel a draft...\n";
		if (caveRooms[caveRooms[currentRoom].rooms[i]].wump)
			std::cout << "I smell a horrid stench...\n";
	}

	return 0;
}

void Cave::printRooms() {
	std::ofstream fout("caveLayout.txt");


	for (auto v : caveRooms) {
		fout << v.desc << "\t" << v.num << " bats: " << v.bats << " pits: " << v.pit << " wump: " << v.wump << ' ';
		fout << v.rooms[0] << ", ";
		fout << v.rooms[1]<< ", ";
		fout << v.rooms[2] << ", " << std::endl;
		fout << std::endl;
	}

}

//Connects rooms randomly
void Cave::connectRooms() {

	int temp = 0;

	//There are total of 20 rooms
	for (auto i = 0; i < 20; i++) {

		//Label to not let the counter go up
	generate:
		//Check if the current room is is already connected to 3
		if (caveRooms[i].con == 3) {
			//This is the point where its safe to asume all the rooms are connected
			if (i + 2 >= 19)
				break;
			//We go from bottom to up
			//Numbers before are already connected so we redefine random generator
			//Going from current number and
			//Adds 2 to because of the loop circumstances
			dis = std::uniform_int_distribution<int>(i + 2, 19);
			continue;
		}

		//Get a random room number
		temp = dis(gen);

		//If this random noom number is already connected to 3 restart
		if (caveRooms[temp].con == 3)
			goto generate;

		//If the current room is already connected to the random room restart
		if (caveRooms[i].rooms[0] == caveRooms[temp].num || caveRooms[i].rooms[1] == caveRooms[temp].num)
			goto generate;

		//Rooms connect to each other and connections go up by 1
		caveRooms[i].rooms[caveRooms[i].con] = caveRooms[temp].num;
		caveRooms[i].con++;
		caveRooms[temp].rooms[caveRooms[temp].con] = caveRooms[i].num;
		caveRooms[temp].con++;

		goto generate;

	}

	//Reset dis for the later use in functions
	dis = std::uniform_int_distribution<int>(0, 19);
}

void Cave::initRooms() {


	//Bat and pits location
	int locBatPit[2][3] = { {0, 0, 0}, {0, 0, 0} };

	//Wumpus location
	int wumpus = dis(gen);

	int temp;
	int i = 1;

	while (true) {
		temp = dis(gen);
		
		//If the random room is wumpus room restart
		if (wumpus == temp)
			continue;

		//Bats first
		if (locBatPit[0][0] != 2) {
			if (i == 1) {
				locBatPit[0][i] = temp;
				++i;
				++locBatPit[0][0];
				continue;
			}
			else if (temp == locBatPit[0][1])
				continue;
			else {
				locBatPit[0][i] = temp;
				i = 1;
				++locBatPit[0][0];
				continue;
			}
		}

		//Then pits
		//Pits can be at the same position as bats
		if (locBatPit[1][0] != 2) {
			if (i == 1) {
				locBatPit[1][i] = temp;
				++i;
				++locBatPit[1][0];
				continue;
			}
			else if (temp == locBatPit[1][1])
				continue;
			else {
				locBatPit[1][i] = temp;
				i = 1;
				++locBatPit[1][0];
				break;
			}
		}

	}

	//Putting in all the values
	caveRooms[wumpus].wump = true;
	wumpusRoom = wumpus;

	caveRooms[locBatPit[0][1]].bats = true;
	caveRooms[locBatPit[0][2]].bats = true;

	caveRooms[locBatPit[1][1]].pit = true;
	caveRooms[locBatPit[1][2]].pit = true;
}

void Cave::gotoRoom(int room) {
	if (room == -1)
		currentRoom = dis(gen);
	else
		currentRoom = room;
}

bool Cave::playerMove(int room) {
	for (auto i = 0; i < 3; i++) {
		if (caveRooms[currentRoom].rooms[i] == room) {
			currentRoom = room;
			return false;
		}
	}
	return true;
}

void Cave::playerShoot(int room) {
	if (caveRooms[room].wump)
		wumpState = false;
	else {
		std::cout << "You missed wumpus has changed locations!";
		caveRooms[wumpusRoom].wump = false;
		wumpusRoom = dis(gen);
		caveRooms[wumpusRoom].wump = true;
	}

}