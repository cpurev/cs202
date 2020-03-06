//Cave generator for the hunt the wumpus game

#ifndef WUMPUS_CAVE
#define WUMPUS_CAVE

#include <iostream>
#include <vector>

class Cave {
public:

	~Cave();

	//Connects the rooms randomly
	void connectRooms();

	//Initilize the rooms with their description
	void initRooms();

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {

		std::weak_ptr<CaveNode> rooms[MaxAdjacentRooms];

		std::string desc = ""; // a long description of this room

		bool bats = false , pit = false, wump = false;
		// constructor should initialize rooms to nullptr

		CaveNode();

	};


	//std::vector<std::shared_ptr<CaveNode>> caveRooms;
	CaveNode* caveRooms[20];

	int currentRoom;


};

#endif // !WUMPUS_CAVE
