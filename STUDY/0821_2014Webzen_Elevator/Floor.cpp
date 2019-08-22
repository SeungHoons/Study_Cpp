#include "Floor.h"
#include "People.h"



Floor::Floor()
{
	upButton = false;
	downButton = false;
}


Floor::~Floor()
{
}

void Floor::init(int _num)
{
	floorNum = _num;
}

void Floor::update()
{
	for (int i=0; i < waitPeople.size(); i++)
	{
		if (floorNum > waitPeople[i]->getDestination())
		{
			upButton = true;
		}
		else 
		{
			downButton = true;
		}
	}
}

void Floor::addPeople()
{
	waitPeople.push_back(new People());
}

int Floor::getPeopleNum()
{
	return waitPeople.size();
}
