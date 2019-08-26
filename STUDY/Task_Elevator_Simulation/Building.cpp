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
	cout << "\n\n\n\n\n\n 모드를 선택하세요. \n1. 수동\n2. 자동\n";
	cin >> input;
	autoMode = input - 1;
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

	if (autoMode)
	{
		count++;
		if (count >= 3)
		{
			randomPeople();
			count = 0;
		}
		pElevatorManager->update();
		equelElevator();
	}
	else
	{
		pElevatorManager->update();
		equelElevator();
	}

	//test1(pElevatorManager->getPointer());
}

void Building::print()
{
	//고치기
	Elevator *tempEelevator = pElevatorManager->getPointer();

	for (int i = MAX_FLOOR - 1; i > -1; i--)
	{
		cout << "ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ ";
		cout << floor[i].waitPeople.size() << " ";
		for (int j = 0; j < MAX_ELEVATOR; j++)
		{
			if ((tempEelevator[j].getFloor()) == i)
			{
				switch (j)
				{
				case 0:
					cout << "①  ";
					break;
				case 1:
					cout << "②  ";
					break;
				case 2:
					cout << "③  ";
					break;
				case 3:
					cout << "④  ";
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
			cout << "☜";
		cout << "\n";
	}

	pElevatorManager->print();
}

void Building::addPeople()
{
	People* nP;
	nP = new People();
	nP->setDestination(cursor);

	floor[cursor].waitPeople.insert(pair<int, People*>(nP->getDestination(), nP));
	changeButton(cursor);
	pElevatorManager->call(cursor, &(floor[cursor].button));
}

void Building::randomPeople()
{
	int random = rand() % MAX_FLOOR;

	People* nP;
	nP = new People();
	nP->setDestination(random);

	floor[random].waitPeople.insert(pair<int, People*>(nP->getDestination(), nP));
	changeButton(random);
	pElevatorManager->call(random, &(floor[random].button));
}


void Building::callElevator()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (floor[i].button.downButton || floor[i].button.upButton)
		{
			pElevatorManager->call(i, &(floor[i].button));
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

void Building::equelElevator()
{
	for (int i = 0; i < MAX_FLOOR; i++)
	{
		if (floor[i].waitPeople.size() > 0)
		{
			for (auto iter = floor[i].waitPeople.begin(); iter != floor[i].waitPeople.end(); iter++)
			{
				if (pElevatorManager->checkFloor((*iter).second))
				{
					floor[i].waitPeople.erase(iter);
					break;
				}
			}
		}
	}
}
