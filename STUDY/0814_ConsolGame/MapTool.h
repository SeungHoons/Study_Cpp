#pragma once
#include "Global.h"
#include <vector>

using namespace std;


class Map;
class Player;
class MapTool
{
private:
	vector<Map*> vecMap;
	POINT point;
	int currentMap;
public:
	MapTool();
	~MapTool();

	//�޴�
	void mainMenu();
	int toolMain();
	void newMap();
	void loadMap();
	void save();

	//��
	void addMap(int _height, int _width);


};

