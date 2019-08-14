#include "MapTool.h"
#include "Map.h"



MapTool::MapTool()
{
	*map = new Map[3];
	for (int i = 0; i < 3; i++)
	{
		map[i] = new Map[3];
	}
}


MapTool::~MapTool()
{
}

void MapTool::printMenu()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t 사이즈를 입력하시요. ?  x  ?" << endl;
	cin >> input;
}

void MapTool::toolMenu()
{
}

void MapTool::save()
{
}

void MapTool::exit()
{
}
