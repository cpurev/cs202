//cave.hpp
//2020-2-2
//Chuluunbat Purev
//Spelunking through Cave

#include <iostream>
#include <vector>
#include <sstream>


#ifndef CAVE_HPP

#define CAVE_HPP

class Cave {
public:

	// what is the number of rooms in the cave?
	int size() const;

	// return current room
	int getCurrentRoom();

	// go to room in the cave complex
	void gotoRoom(int room);

	// which adjacent room? 0, 1, or 2?
	void gotoAdjacentRoom(int room);

	// connect two rooms together
	void connect(int room1, int room2);

	// print the short description of the room
	void printShortDesc(int room) const;

	// print the long description of the room
	void printLongDesc(int room) const;

	// save rooms to an output stream
	void saveRooms(std::ostream& os) const;

	// read rooms from an input stream
	void readRooms(std::istream& is);

private:

	static constexpr int MaxAdjacentRooms = 3;

	struct CaveNode {

		std::weak_ptr<CaveNode> rooms[MaxAdjacentRooms];

		std::string shortdesc; // a short description of this room
		std::string longdesc; // a long description of this room

		// constructor should initialize rooms to nullptr

		CaveNode() {
			shortdesc = "";
			longdesc = "";
		}

	};

	using CaveNodePtr = std::shared_ptr<CaveNode>;
	std::vector<CaveNodePtr> caveRooms; 
	int currentRoom;

};

#endif // CAVE_HPP