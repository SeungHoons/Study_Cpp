#include "MapManager.h"
#include "ResManager.h"
#include "Tile.h"



MapManager::MapManager()
{
}


MapManager::~MapManager()
{
}

void MapManager::init()
{
	int index;
	for (int i = 0; i < MAP_TILE_WIDHT_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_TILE_WIDHT_HEIGHT; j++)
		{
			index = (i * MAP_TILE_WIDHT_HEIGHT) + j;
			m_vecTile.push_back(new Tile());
			RECT rc = { (TILE_START_POINT_X)+(j*TILE_SIZE),(i*TILE_SIZE)+(TILE_START_POINT_Y), (j + 1)*TILE_SIZE, (i + 1)*TILE_SIZE };

			m_vecTile[index]->init(ResManager::getInst()->getLoadBitMap(index),&rc);
		}
	}
}

void MapManager::update()
{
}

void MapManager::render(HDC _hdc)
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		(*iter)->render(_hdc);
	}
}
