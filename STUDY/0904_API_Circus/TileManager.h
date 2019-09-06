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
	

	void init();
	void update();
	void 
};

