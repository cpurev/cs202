//wumpusCave.cpp
//Chuluunbat Purev
//2020-03-04
//Wumpus Cave generator body

#include "wumpusCave.hpp"
#include <random>
#include <string>

Cave::Cave() : currentRoom(0){
	for (auto i = 0; i < 21; i++) {
		std::string str("This is room: " + std::to_string(i));
		CaveNode cn;
		cn.desc = str;
		cn.num = i;
		caveRooms.push_back(std::make_shared<CaveNode>(cn));
	}
}

void Cave::printRooms() {
	for (auto v : caveRooms) {
		std::cout << v->desc << "\t" /*<< v->rooms[0]->num << ", " << v->rooms[1]->num << ", "
			<< v->rooms[2]->num*/ << std::endl;
	}

}

void Cave::connectRooms() {

	//Random generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 20);

	int temp = 0;

	for (auto i = 0; i <= 20; i++) {

	generate:
		if (caveRooms[i]->con == 3) {
			if (i + 2 >= 20)
				break;
			dis = std::uniform_int_distribution<int>(i + 2, 20);
			continue;
		}

		temp = dis(gen);

		if (caveRooms[temp]->con == 3)
			goto generate;
		caveRooms[i]->rooms[caveRooms[i]->con] = caveRooms[temp];
		++caveRooms[i]->con;
		caveRooms[temp]->rooms[caveRooms[temp]->con] = caveRooms[i];
		++caveRooms[temp]->con;

		goto generate;

	}
}

void Cave::initRooms() {

	//Random generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 20);

	//Bat and pits location
	int locBatPit[2][3] = { {0, 0, 0}, {0, 0, 0} };

	//Wumpus location
	int wumpus = dis(gen);

	int temp;
	int i = 1;

	while (true) {

		temp = dis(gen);
		if (wumpus == temp)
			continue;

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

	caveRooms[wumpus]->wump = true;
	caveRooms[wumpus]->desc += "\n~Wumpus has eaten you!";

	caveRooms[locBatPit[0][1]]->bats = true;
	caveRooms[locBatPit[0][1]]->desc += "\nBATS! ~They carried you to a random room!";
	caveRooms[locBatPit[0][2]]->bats = true;
	caveRooms[locBatPit[0][2]]->desc += "\nBATS! ~They carried you to a random room!";

	caveRooms[locBatPit[1][1]]->pit = true;
	caveRooms[locBatPit[1][1]]->desc += "\nAAAAAAAAAAAAAAAAAAH! ~You Fell";
	caveRooms[locBatPit[1][2]]->pit = true;
	caveRooms[locBatPit[1][2]]->desc += "\nAAAAAAAAAAAAAAAAAAH! ~You Fell";


	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << locBatPit[i][j] << " ";
	//	}

	//	// Newline for new row 
	//	std::cout << std::endl;
	//}

	//std::cout << wumpus << std::endl;


}
