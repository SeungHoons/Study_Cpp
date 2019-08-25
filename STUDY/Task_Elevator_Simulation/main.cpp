#include <iostream>
#include <time.h>
#include <conio.h>
#include "Building.h"
using namespace std;
Building building;

void print()
{
	system("cls");
	building.print();
}

void input()
{
	if (kbhit())
	{
		char input;
		input = _getch();
		switch (input)
		{
		case 'w':
			building.cursorUp();
			break;
		case 's':
			building.cursorDown();
			break;
		case 'z':
			building.addPeople();
			break;

		default:
			break;
		}
	}
}

void update()
{

}

int main()
{
	srand(time(nullptr));

	building.setMode();
	building.init();
	print();

	while (true)
	{
		input();
		print();
		update();

		_sleep(1000 / 5);
	}
	return 0;
}