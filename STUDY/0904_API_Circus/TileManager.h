#pragma once
#include "Global.h"

class Tile;
class TileManager
{
private:
	vector<Tile*> m_vecTile;
public:
	TileManager();
	~TileManager();
	

	void init(int _num);
	void update();
	void render(HDC _hdc);

	void setPosition(int _x);
};

