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

	//UI
	void setMode();
	void cursorUp() { cursor++; }
	void cursorDown() { cursor--; }

	void addPeople();
	void randomPeople();
	
	void update();
	void search();
	void print();
};

