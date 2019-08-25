#include "Floor.h"
#include "People.h"
#include "Elevator.h"



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

People * Floor::relayPeople()
{
	//waitPeople.
	return waitPeople[1];
}

void Floor::checkPeople(Elevator * _pElevator)
{
	vector< deque<People*>::iterator>  temp;
	for (auto iter = waitPeople.begin(); iter != waitPeople.end(); iter++)
	{
		if ((*iter)->getDiarecton() == _pElevator->getState())
		{
			_pElevator->inElevator(*iter);
			temp.push_back(iter);
		}
	}

	for (int i = temp.size(); i >= 0; i--)
	{
		waitPeople.erase(temp[i]);
	}
}
