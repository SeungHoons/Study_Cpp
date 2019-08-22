#include "Floor.h"
#include "People.h"



Floor::Floor()
{
	
}


Floor::~Floor()
{
}

void Floor::init(int _num)
{
	floorNum = _num;
}

void Floor::addPeople()
{
	waitPeple.push_back(new People());
}

int Floor::getPeopleNum()
{
	return waitPeple.size();
}
