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

}