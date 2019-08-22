#include "ElevatorManager.h"
#include "Elevator.h"



ElevatorManager::ElevatorManager()
{
	pElevator = new Elevator[4];
	pElevator[0].setType(LOW);
	pElevator[1].setType(HIGH);
	pElevator[2].setType(HIGH);
	pElevator[3].setType(ALL);
}


ElevatorManager::~ElevatorManager()
{
}

void ElevatorManager::update()
{
	
}

void ElevatorManager::print()
{
	cout << "\n\n\n";
	cout << "\t===엘리베이터 안내===\t\t ===엘리베이터 현황===" << endl;
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		cout << "\t " << i+1 << "호기 ";

		if (i == 0)
			cout << "저층 운행 ";
		else if (i == 3)
			cout << "전층 운행 ";
		else
			cout << "고층 운행 ";
		pElevator[i].print();

	}
}
