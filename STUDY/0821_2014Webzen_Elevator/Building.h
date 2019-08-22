#pragma once
#include"Global.h"

class ElevatorManager;
class Floor;
class Building
{
	bool autoMode;
	ElevatorManager *pElevatorManager;
	Floor *pFloor;
	int cursor;
public:
	Building();
	~Building();

	void setMode();
	void cursorUp() { cursor++; }
	void cursorDown() { cursor--; }

	void addPeople();
	void randomPeople();
	
	void print();
};

