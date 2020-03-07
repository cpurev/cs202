//Cave generator for the hunt the wumpus game

#ifndef WUMPUS_CAVE
#define WUMPUS_CAVE

#include <vector>
#include <iostream>

class Cave {
public:

	bool playerState, wumpState;
	int arrows;

	//Initlize caveRooms and other variables
	Cave();

	//~Cave();

	//Connects the rooms randomly
	void connectRooms();

	//Initilize the rooms with their description
	void initRooms();

	//Just print rooms
	void printRooms();

	//Return currentRoom variable
	int getCurrentRoom();

	//Return currentRooms hazard
	int hazard();

	//Return adjacent rooms hazard hints
	int hazardHint();

	//Get adjacent rooms number
	std::string getAdjRooms();

	//Go to room
	//-1 goes to random room
	void gotoRoom(int room);

	//Move player to adj room
	//Checks if its adj room
	bool playerMove(int room);

	//Let the player shoot at any room
	//Limited arrows
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
