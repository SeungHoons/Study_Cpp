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
	cout << "\t===���������� �ȳ�===\t\t ===���������� ��Ȳ===" << endl;
	for (int i = 0; i < MAX_ELEVATOR; i++)
	{
		cout << "\t " << i+1 << "ȣ�� ";

		if (i == 0)
			cout << "���� ���� ";
		else if (i == 3)
			cout << "���� ���� ";
		else
			cout << "���� ���� ";
		pElevator[i].print();

	}
}
