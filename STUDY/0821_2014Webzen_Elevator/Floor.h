#pragma once
#include "Global.h"

class People;
class Floor
{
	int floorNum;
	deque<People*> waitPeple;
public:
	Floor();
	~Floor();

	void init(int _num);

	void addPeople();
	int getPeopleNum();
};

