//Cave generator for the hunt the wumpus game

#ifndef WUMPUS_CAVE
#define WUMPUS_CAVE

#include <vector>
#include <iostream>

class Cave {
public:

	bool playerState, wumpState, arrows;

	Cave();

	//~Cave();

	//Connects the rooms randomly
	void connectRooms();

	//Initilize the rooms with their description
	void initRooms();

	//Just print rooms
	void printRooms();

	int getCurrentRoom();

	int hazard();

	int hazardHint();

	std::string getAdjRooms();

	void gotoRoom(int room);

	bool playerMove(int room);

	void playerShoot(int room);

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {

		//Adjacent Rooms Pointer
		//std::shared_ptr<CaveNode> rooms[MaxAdjacentRooms];
		int rooms[MaxAdjacentRooms] = {-1, -1, -1};

		//Number of room connections
		int con = 0;
		
		//Room number
		int num = 0;

		//Description for hazards and room number holder
		std::string desc = ""; // a long description of this room

		//Hazard indicators
		bool bats = false , pit = false, wump = false;

		// constructor should initialize rooms to nullptr
	//	CaveNode() : rooms(nullptr) {}

	};


	//std::vector<std::shared_ptr<CaveNode>> caveRooms;
	//Cave Rooms
	//CaveNode caveRooms[21] = {};
	std::vector<CaveNode> caveRooms;

	int currentRoom = 0;


};

#endif // !WUMPUS_CAVE
