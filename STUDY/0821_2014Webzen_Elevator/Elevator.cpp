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

	cout << "\t\t ��:" << floor + 1 << "  �ο�:" << people << "  ����:" << weight << "  ����:";
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
