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

void Elevator::update()
{
}

void Elevator::move()
{
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

	arrival();

	for (int i = 0; i < inPeople.size(); i++)
	{
		inPeople[i]->countUp();
	}
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
	inPeople.push_back(_pPeople);
	peopleNum = inPeople.size();
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
	
	for (auto iter = inPeople.begin(); iter != inPeople.end(); iter++)
	{
		//if()

		//(*iter)->getDestination
	}
}
