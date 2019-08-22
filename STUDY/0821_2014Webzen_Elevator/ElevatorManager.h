#pragma once
#include "Global.h"
#define MAX_ELEVATOR 4

class Elevator;
class People;
class ElevatorManager
{
	Elevator *pElevator;
	deque<People*> inPeople;
public:
	ElevatorManager();
	~ElevatorManager();

	void update();
	Elevator* getPointer() { return pElevator; }
	
	void print();
};

