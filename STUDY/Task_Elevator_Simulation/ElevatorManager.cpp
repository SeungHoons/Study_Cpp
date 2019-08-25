#include "ElevatorManager.h"
#include "Elevator.h"



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

void ElevatorManager::call(int _floor, Button* _pButton)
{

}