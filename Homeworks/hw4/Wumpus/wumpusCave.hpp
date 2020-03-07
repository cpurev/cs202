//Cave generator for the hunt the wumpus game

#ifndef WUMPUS_CAVE
#define WUMPUS_CAVE

#include <vector>
#include <iostream>

class Cave {
public:

	Cave();

	//~Cave();

	//Connects the rooms randomly
	void connectRooms();

	//Initilize the rooms with their description
	void initRooms();

	//Just print rooms
	void printRooms();

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {

		//Adjacent Rooms Pointer
		std::weak_ptr<CaveNode> rooms[MaxAdjacentRooms];

		//Number of room connections
		int con = 0;

		//Description for hazards and room number holder
		std::string desc = ""; // a long description of this room

		//Hazard indicators
		bool bats = false , pit = false, wump = false;

		// constructor should initialize rooms to nullptr
	//	CaveNode() : rooms(nullptr) {}

	};


	//std::vector<std::shared_ptr<CaveNode>> caveRooms;
	CaveNode caveRooms[21] = {};

	int currentRoom = 0;


};

#endif // !WUMPUS_CAVE
