#include "ElevatorManager.h"
#include "Elevator.h"



ElevatorManager::ElevatorManager()
{
	pElevator = new Elevator[4];
	/*pElevator[0].setType(LOW);
	pElevator[1].setType(HIGH);
	pElevator[2].setType(HIGH);
	pElevator[3].setType(ALL);*/
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
	cout << "\t===엘리베이터 안내===\t\t ===엘리베이터 현황===" << endl;
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		cout << "\t " << i + 1 << "호기 ";

		if (pElevator[i].getType() == LOW)
			cout << "저층 운행 ";
		else if (pElevator[i].getType() == ALL)
			cout << "전층 운행 ";
		else
			cout << "고층 운행 ";
		pElevator[i].print();

	}
}


void ElevatorManager::call(int _floor, const Button* _pButton)
{
	int min = MAX_ELEVATOR;
	


	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		pair<int, Elevator*> shotElevator((abs(pElevator[i].getFloor() - _floor)), &pElevator[i]);
		shortElevator.insert(shotElevator);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////반복되는거 함수화 시키기////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////
	for (auto iter = shortElevator.begin(); iter != shortElevator.end(); iter++)
	{
		
		if (_pButton->downButton)
		{
			if ((*iter).second->getState() == DOWN && ((*iter).second->getFloor() - _floor)>=0)
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
		if(_pButton->upButton)
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
	

	/*Elevator* minElevator;
	for (auto iter = pElevator; iter < pElevator + MAX_ELEVATOR; iter++)
	{
		if (min > abs(iter->getFloor() - _floor))
		{
			minElevator = iter;
		}
	}

	if ((minElevator->getFloor() - _floor) > 0)
	{
		minElevator->setState(DOWN);
	}
	else
	{
		minElevator->setState(UP);
	}*/
}


void ElevatorManager::serchElevator()
{
}

void ElevatorManager::arrival()
{
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		pElevator[i].
	}
}
