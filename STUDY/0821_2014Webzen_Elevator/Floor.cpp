#include "Floor.h"
#include "People.h"



Floor::Floor()
{
	button.upButton = false;
	button.downButton = false;
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

}

void Floor::checkButton()
{
	for (int i = 0; i < waitPeople.size(); i++)
	{
		if (floorNum < waitPeople[i]->getDestination())
		{
			button.upButton = true;
			button.call = true;
		}
		else
		{
			button.downButton = true;
			button.call = true;
		}

		waitPeople[i]->countUp();
	}
}

void Floor::addPeople()
{
	People* nP;
	nP = new People();
	nP->setDestination(floorNum);
	waitPeople.push_back(nP);
	checkButton();
}

int Floor::getPeopleNum()
{
	return waitPeople.size();
}
