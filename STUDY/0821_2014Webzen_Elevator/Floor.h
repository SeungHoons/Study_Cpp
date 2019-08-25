#pragma once
#include "Global.h"

class People;
class Elevator;
class Floor
{
	int floorNum;
	deque<People*> waitPeople;
	Button button;

public:
	Floor();
	~Floor();

	void init(int _num);

	//안쓰면 지움
	//void setUpbutton() { upButton = true; }
	//void setDownbutton() { downButton = true; }
	void update();
	void checkButton();

	void addPeople();
	int getPeopleNum();
	People* relayPeople();
	Button* getButton() { return &button; }
	void checkPeople(Elevator* _pElevator);
};

