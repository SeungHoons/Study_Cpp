#pragma once
#include "Global.h"
#define MAX_ELEVATOR 4

class Elevator;
class People;
class Floor;
class ElevatorManager
{
	Elevator *pElevator;
	map<int,Elevator*> shortElevator;
public:
	ElevatorManager();
	~ElevatorManager();

	void update();
	void print();

	Elevator* getPointer() { return pElevator; }
	
	void call(int _floor , const Button* _pButton);
	void serchElevator();
	void whareElevator(int index, Floor& _pFloor);
	void floorToElevator(Floor* _pFloor);

};

