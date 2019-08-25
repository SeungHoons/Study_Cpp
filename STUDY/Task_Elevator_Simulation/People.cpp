#include "People.h"



People::People()
{
	floor = 0;
	count = 0;
}


People::~People()
{
}



void People::setDestination(int _floor)
{
	floor = _floor;


	if (floor == 0)
	{
		while (true)
		{
			destination = rand() % MAX_FLOOR;
			if (floor == destination)
				continue;

			break;
		}
	}
	else
	{
		destination = 0;
	}

	setDirection();
}

void People::setDirection()
{
	if (floor - destination < 0)
		direction = UP;
	else
		direction = DOWN;
}
