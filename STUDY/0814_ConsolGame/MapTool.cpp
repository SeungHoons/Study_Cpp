#include "MapTool.h"
#include "Map.h"
#include "Player.h"
#include <string>
#include <stdio.h>



MapTool::MapTool()
{
	currentMap = 0;
}


MapTool::~MapTool()
{
}

void MapTool::mainMenu()
{
	int input;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t\t\t\t 1. ���θ����" << endl;
	cout << "\t\t\t\t\t\t\t 2. �� �����ϱ�" << endl;
	cout << "\t\t\t\t\t\t\t 3. ������" << endl;
	cout << "\t\t\t\t\t\t\t ��ȣ�� �Է����ּ��� : ";
}

int MapTool::toolMain()
{

	vecMap[currentMap]->printMap();

	cout << "\t 1.�����\t 2.��\t 3.���� ������ġ\t 4.������\t 5.��\t 6.����\t 7.������" << endl;


	if (_kbhit())
	{
		char cInput;
		cInput = _getch();
		switch (cInput)
		{
		case 'w':
			point.height--;
			break;
		case 's':
			point.height++;
			break;
		case 'a':
			point.width--;
			break;
		case 'd':
			point.width++;
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
			vecMap[currentMap]->setBlock(point.height, point.width, atoi(&cInput));
			return 1;
			break;
		case '6':	//����
			save();
			break;
		case '7':	//������
			return 4;

			break;
		default:
			break;
		}
	}
	return 1;

}

void MapTool::newMap()
{
	int height, width;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t ����� �Է����ּ���. ���� x ���� : ";
	cin >> width >> height;
	addMap(height, width);
}

void MapTool::loadMap()
{
}

void MapTool::save()
{
	int saveNum = currentMap;
	char tc;
	sprintf(&tc, "%d", saveNum);
	string fname = "map_";
	fname += tc;
	fname += ".txt";

	FILE* checkP = fopen(fname.c_str(),"r");
	while (checkP != nullptr)
	{
		fname.clear();
		fname = "map_";
		saveNum++;
		sprintf(&tc, "%d", saveNum);
		fname += tc;
		fname += ".txt";
		checkP = fopen(fname.c_str(), "r");

	}

	FILE* fp = fopen(fname.c_str(), "w");

	POINT mapPoint = vecMap[currentMap]->getMapxy();
	fprintf(fp, "%d %d\n", mapPoint.height,
		mapPoint.width);

	for (int i = 0; i < mapPoint.height; i++)
	{
		for (int j = 0; j < mapPoint.width; j++)
		{
			int tempdd = vecMap[currentMap]->getBlock(i, j);
			fprintf(fp, "%d,", vecMap[currentMap]->getBlock(i, j));
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	if (checkP != nullptr)
	{
		fclose(checkP);
	}
	tc = '\0';
}



void MapTool::addMap(int _height, int _width)
{
	vecMap.push_back(new Map());
	vecMap[vecMap.size() - 1]->init(_height, _width);
	point = { _height/2, _width/2 };
	vecMap[currentMap]->setPlayer(&point);
}

