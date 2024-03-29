#include "Building.h"
#include "Floor.h"
#include "ElevatorManager.h"
#include "Elevator.h"



Building::Building()
{
	pElevatorManager = new ElevatorManager();
	pFloor = new Floor[MAX_FLOOR];
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		pFloor[i].init(i);
	}
	cursor = 0;
}


Building::~Building()
{
}

void Building::setMode()
{
	int input;
	cout << "\n\n\n\n\n\n 乞球研 識澱馬室推. \n1. 呪疑\n2. 切疑\n";
	cin >> input;
	autoMode = input - 1;
}



void Building::addPeople()
{
	pFloor[cursor].addPeople();
	callElevator();
}

void Building::randomPeople()
{
	int random = rand() % MAX_FLOOR;

	pFloor[random].addPeople();
	callElevator();
}

void Building::update()
{
	pElevatorManager->update();
	//for (int i = 0; i < MAX_FLOOR; i++)
	//{
	//	pFloor[i].update();
	//}
	equelFloorEelevator();
}

void Building::callElevator()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (pFloor[i].getButton()->call == true)
		{
			pElevatorManager->call(i, pFloor[i].getButton());
		}
	}
}

void Building::equelFloorEelevator()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (pFloor[i].getPeopleNum() > 0)
		{
			pElevatorManager->whareElevator(i, pFloor[i]);
		}
	}
}



void Building::print()
{
	//壱帖奄
	Elevator *tempEelevator = pElevatorManager->getPointer();

	for (int i = MAX_FLOOR -1; i > -1; i--)
	{
		cout << "けけけけけけけけけけけけ ";
		cout << pFloor[i].getPeopleNum()<<" ";
		for (int j = 0; j < MAX_ELEVATOR; j++)
		{
			if ((tempEelevator[j].getFloor()) == i)
			{
				switch (j)
				{
				case 0:
					cout << "��  ";
					break;
				case 1:
					cout << "��  ";
					break;
				case 2:
					cout << "��  ";
					break;
				case 3:
					cout << "��  ";
					break;
				default:
					break;
				}
			}
			else
			{
				cout << "    ";
			}
		}
		if (i == cursor)
			cout << "∃";
		cout << "\n";
	}

	pElevatorManager->print();
}


