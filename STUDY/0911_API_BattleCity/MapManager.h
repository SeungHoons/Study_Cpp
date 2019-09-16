#pragma once
#include "Global.h"

class Tile;
class MapManager
{
	vector<Tile*> m_vecTile;
public:
	MapManager();
	~MapManager();


	void init();
	void update();
	void render(HDC _hdc);

};

