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

	//�Ⱦ��� ����
	//void setUpbutton() { upButton = true; }
	//void setDownbutton() { downButton = true; }
	void update();

	void addPeople();
	int getPeopleNum();
};

