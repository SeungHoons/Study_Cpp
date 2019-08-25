#pragma once
#include "Global.h"

class Elevator;
class People;

class ElevatorManager
{
private:
	Elevator *pElevator;

public:
	ElevatorManager();
	~ElevatorManager();

	void update();
	void print();

	void call(int _floor, Button* _pButton);

	//프린트하려고. 고쳐야함
	Elevator* getPointer() { return pElevator; }
};

