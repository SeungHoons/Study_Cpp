#include "Building.h"
#include "Floor.h"
#include "ElevatorManager.h"



Building::Building()
{
	pElevatorManager = new ElevatorManager();
	pFloor = new Floor[MAX_FLOOR];
}


Building::~Building()
{
}

void Building::addPeople()
{
}

void Building::print()
{
	for (int i = MAX_ELEVATOR; i > -1 ; i--)
	{
		cout << "けけけけ";
		cout <
	}
}
