#include "People.h"



People::People()
{
	floor = 0;
}


People::~People()
{
}

void People::setDestination()
{
	while (true)
	{
		destination = rand() % MAX_FLOOR;
		if (floor == destination)
			continue;

		break;
	}
}
