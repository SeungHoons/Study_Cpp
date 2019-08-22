#pragma once
#include "Global.h"

class People;
class Floor
{
	int floorNum;
	deque<People*> waitPeople;
	bool upButton;
	bool downButton;

public:
	Floor();
	~Floor();

	void init(int _num);

	//안쓰면 지움
	//void setUpbutton() { upButton = true; }
	//void setDownbutton() { downButton = true; }
	void update();

	void addPeople();
	int getPeopleNum();
};

