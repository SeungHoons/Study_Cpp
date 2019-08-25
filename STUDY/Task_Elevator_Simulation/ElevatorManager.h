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

	//����Ʈ�Ϸ���. ���ľ���
	Elevator* getPointer() { return pElevator; }
};

