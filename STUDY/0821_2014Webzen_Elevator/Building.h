#pragma once
#include"Global.h"

class ElevatorManager;
class Floor;
class Building
{
	ElevatorManager *pElevatorManager;
	Floor *pFloor;
public:
	Building();
	~Building();

	void addPeople();
	void print();
};

