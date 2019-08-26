#include "Elevator.h"
#include "People.h"



Elevator::Elevator()
{
	floor = 0;
	peopleNum = 0;
	weight = 0;
	state = STOP;
}


Elevator::~Elevator()
{
}



void Elevator::print()
{

	cout << "\t\t 층:" << floor + 1 << "  인원:" << peopleNum << "  무게:" << weight << "  상태:";
	switch (state)
	{
	case UP:
		cout << "Going UP";
		break;
	case DOWN:
		cout << "Going DOWN";
		break;
	case STOP:
		cout << "STOP";
		break;
	default:
		break;
	}
	cout << "\n";


}

void Elevator::move()
{
	arrival();

	switch (state)
	{
	case UP:
		floor++;
		break;
	case DOWN:
		floor--;
		break;
	case STOP:
		break;
	default:
		break;
	}


	/*for (int i = 0; i < peopleInElevator.size(); i++)
	{
		peopleInElevator[i].second->countUp();
	}*/
	//나중에 카운트 샐때
}

void Elevator::setState(STATE _state)
{
	state = _state;
}

void Elevator::setType(ELEVATOR_TYPE _type)
{
	type = _type;
}

void Elevator::inElevator(People * _pPeople)
{
	peopleInElevator.insert(pair<int, People*>(_pPeople->getDestination(), _pPeople));
	peopleNum = peopleInElevator.size();
}

void Elevator::arrival()
{
	if (target == floor)
	{
		state = STOP;
	}
}

void Elevator::targetUpdate()
{

	for (auto iter = peopleInElevator.begin(); iter != peopleInElevator.end(); iter++)
	{
		//if()

		//(*iter)->getDestination
	}
}

void Elevator::setTarget(int _target)
{
	if (state == UP)
	{
		if (target < _target)
		{
			target = _target;
		}
	}
	else if (state == DOWN)
	{
		if (target > _target)
		{
			target = _target;
		}
	}
	else if (state == STOP)
	{
		target = _target;
	}
}