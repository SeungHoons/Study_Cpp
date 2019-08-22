#include "Elevator.h"



Elevator::Elevator()
{
	floor = 0;
	people = 0;
	weight = 0;
	state = STOP;
}


Elevator::~Elevator()
{
}

void Elevator::print()
{

	cout << "\t\t 층:" << floor + 1 << "  인원:" << people << "  무게:" << weight << "  상태:";
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

void Elevator::move(STATE _state)
{
	switch (_state)
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
}

void Elevator::setState(STATE _state)
{
	state = _state;
}

void Elevator::setType(ELEVATOR_TYPE _type)
{
	type = _type;
}
