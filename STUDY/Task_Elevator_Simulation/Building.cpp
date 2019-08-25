#include "Building.h"
#include "ElevatorManager.h"
#include "Elevator.h"
#include "People.h"

Building::Building()
{
	pElevatorManager = new ElevatorManager();
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
	People* nP;
	nP = new People();
	nP->setDestination(cursor);

	floor[cursor].waitPeople.insert(pair<int, People*>(nP->getDestination(), nP));
	floor[cursor].button = 
	//pFloor[cursor].addPeople();
	//callElevator();
}

void Building::randomPeople()
{
	int random = rand() % MAX_FLOOR;

	//pFloor[random].addPeople();
	//callElevator();
}

void Building::init()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		floor[i].button.call = false;
		floor[i].button.upButton = false;
		floor[i].button.downButton = false;
	}
}

void Building::update()
{
	pElevatorManager->update();
}

void Building::print()
{
	//��ġ��
	Elevator *tempEelevator = pElevatorManager->getPointer();

	for (int i = MAX_FLOOR - 1; i > -1; i--)
	{
		cout << "������������������������ ";
		cout << floor[i].waitPeople.size() << " ";
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


void Building::callElevator()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (floor[i].button.downButton || floor[i].button.upButton)
		{
			//pElevatorManager
		}
	}
}

void Building::changeButton(int index)
{
	for (auto iter = floor[index].waitPeople.begin(); iter != floor[index].waitPeople.end(); iter++)
	{
		if ((*iter).second->getDiarecton() == DOWN)
		{
			floor[index].button.downButton = true;
		}
		else if ((*iter).second->getDiarecton() == UP)
		{
			floor[index].button.upButton = true;
		}
	}
	
}
