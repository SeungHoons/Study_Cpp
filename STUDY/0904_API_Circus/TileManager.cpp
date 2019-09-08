#include "TileManager.h"
#include "Tile.h"


TileManager::TileManager()
{
}


TileManager::~TileManager()
{
}

void TileManager::init(int _num)
{
	for (int i = 0; i < _num; i++)
	{
		m_vecTile.push_back(new Tile());
	}

	for (int i = 0; i < _num; i++)
	{
		if (i % (_num / 2) == 0)
		{
			m_vecTile[i]->init((i*TILE_WIDTH * IMAGE_SIZE_MULTIFLY), true);
		}
		else
			m_vecTile[i]->init((i*TILE_WIDTH * IMAGE_SIZE_MULTIFLY), false);
	}
}

void TileManager::update()
{
}

void TileManager::render(HDC _hdc)
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		(*iter)->render(_hdc);
	}
}

void TileManager::setPosition(int _x)
{
	for (int i = 0; i < m_vecTile.size(); i++)
	{
		m_vecTile[i]->setPosition(_x);
	}
}
