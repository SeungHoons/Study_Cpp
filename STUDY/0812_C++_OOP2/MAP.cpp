
#include "MAP.h"



MAP::MAP()
{
	site = new int*[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		site[i] = new int[WIDTH];
	}
}


MAP::~MAP()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		delete site[i];
	}
	delete site;
}

void MAP::Print()
{
}
