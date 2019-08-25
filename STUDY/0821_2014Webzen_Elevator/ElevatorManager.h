#pragma once
#include "Global.h"
#define MAX_ELEVATOR 4

class Elevator;
class People;
class ElevatorManager
{
	Elevator *pElevator;
	deque<People*> inPeople;
	map<int,Elevator*> shortElevator;
public:
	ElevatorManager();
	~ElevatorManager();

	void update();
	void print();

	Elevator* getPointer() { return pElevator; }
	
	void call(int _floor , const Button* _pButton);
	void serchElevator();
	void arrival();
};

