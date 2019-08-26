#include "ElevatorManager.h"
#include "Elevator.h"
#include "People.h"



ElevatorManager::ElevatorManager()
{
	pElevator = new Elevator[4];
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		pElevator[i].setType(ALL);
	}
}


ElevatorManager::~ElevatorManager()
{
}



void ElevatorManager::update()
{
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		pElevator[i].move();
	}
}
void ElevatorManager::print()
{
	cout << "\n\n\n";
	cout << "\t===���������� �ȳ�===\t\t ===���������� ��Ȳ===" << endl;
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		cout << "\t " << i + 1 << "ȣ�� ";

		if (pElevator[i].getType() == LOW)
			cout << "���� ���� ";
		else if (pElevator[i].getType() == ALL)
			cout << "���� ���� ";
		else
			cout << "���� ���� ";
		pElevator[i].print();

	}
}

void ElevatorManager::call(int _floor, Button* _pButton)
{
	map<int, Elevator*> shortDitanceElevator;

	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		pair<int, Elevator*> tempPair((abs(pElevator[i].getFloor() - _floor)), &pElevator[i]);
		shortDitanceElevator.insert(tempPair);
	}

	for (auto iter = shortDitanceElevator.begin(); iter != shortDitanceElevator.end(); iter++)
	{
		if(_pButton->downButton)
		{
			if ((*iter).second->getState() == DOWN && ((*iter).second->getFloor() - _floor) >= 0)
			{
				(*iter).second->setTarget(_floor);
				break;
			}
			else if ((*iter).second->getState() == STOP)
			{
				(*iter).second->setTarget(_floor);
				if (((*iter).second->getFloor() - _floor) >= 0)
				{
					(*iter).second->setState(DOWN);
				}
				else
				{
					(*iter).second->setState(UP);
				}
				break;
			}
		}

		if (_pButton->upButton)
		{
			if ((*iter).second->getState() == UP && ((*iter).second->getFloor() - _floor) <= 0)
			{
				(*iter).second->setTarget(_floor);
				break;
			}
			else if ((*iter).second->getState() == STOP)
			{
				(*iter).second->setTarget(_floor);
				if (((*iter).second->getFloor() - _floor) <= 0)
				{
					(*iter).second->setState(UP);
				}
				else
				{
					(*iter).second->setState(DOWN);
				}
				break;
			}
		}
	}
}

bool ElevatorManager::checkFloor(People * _people)
{
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		if (pElevator[i].getFloor() == _people->getFloor())
		{
			if ((pElevator[i].getState() == _people->getDiarecton()) || (pElevator[i].getState() == STOP))
			{
				pElevator[i].inElevator(_people);
				return 1;
			}
		}
	}
	return 0;
}
