#pragma once
#include "Global.h"

class People;
class Floor
{
	deque<People*> waitPeple;
public:
	Floor();
	~Floor();


	void addPeople();
};

