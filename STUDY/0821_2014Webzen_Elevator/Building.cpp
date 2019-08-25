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
	cout << "\n\n\n\n\n\n ��带 �����ϼ���. \n1. ����\n2. �ڵ�\n";
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
}

void Building::update()
{
	pElevatorManager->update();
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		pFloor[i].update();
	}
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

void Building::print()
{
	Elevator *tempEelevator = pElevatorManager->getPointer();

	for (int i = MAX_FLOOR -1; i > -1; i--)
	{
		cout << "������������������������ ";
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
			cout << "��";
		cout << "\n";
	}

	pElevatorManager->print();
}


