#include <iostream>
#include "StudentManager.h"
using namespace std;

int main()
{
	StudentManager StManager;

	while (true)
	{
		StManager.PrintMenu();
		int input;
		cin >> input;

		switch (input)
		{
		case 1:
			StManager.InputStudent();
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		default:
			break;
		}
	}

	return 0;
}