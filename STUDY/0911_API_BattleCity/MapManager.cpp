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
			RECT rc = { (TILE_START_POINT_X)+(j*TILE_SIZE),(i*TILE_SIZE) + (TILE_START_POINT_Y), (j + 1)*TILE_SIZE, (i + 1)*TILE_SIZE };

			m_vecTile[index]->init(ResManager::getInst()->getLoadBitMap(index), &rc);
			setCollitionBox(index);
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

void MapManager::setCollitionBox(int _index)
{
	RES_FILE_NAME fileIndex = ResManager::getInst()->getFileIndex(_index);
	POINT point = { 0, 0 };

	switch (fileIndex)
	{
	case FILE_BLOCK00:
	case FILE_BLOCK08:
		for (int i = 0; i < 2; i++)
		{
			point.x = 0;
			for (int j = 0; j < 2; j++)
			{
				m_vecTile[_index]->setInRect(point);
				point.x += 20;
			}
			point.y += 20;
		}
		break;
	case FILE_BLOCK01:
	case FILE_BLOCK09:
		for (int j = 0; j < 2; j++)
		{
			m_vecTile[_index]->setInRect(point);
			point.x += 20;
		}
		break;
	case FILE_BLOCK02:
	case FILE_BLOCK10:
		for (int i = 0; i < 2; i++)
		{
			m_vecTile[_index]->setInRect(point);
			point.y += 20;
		}
		break;
	case FILE_BLOCK03:
	case FILE_BLOCK11:
		point.y = 20;
		for (int j = 0; j < 2; j++)
		{
			m_vecTile[_index]->setInRect(point);
			point.x += 20;
		}
		break;
	case FILE_BLOCK04:
	case FILE_BLOCK12:
		point.x = 20;
		for (int i = 0; i < 2; i++)
		{
			m_vecTile[_index]->setInRect(point);
			point.y += 20;
		}
		break;

	default:
		break;
	}
}

bool MapManager::checkColltion(RECT* _rc)
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		if ((*iter)->checkColltion(*_rc))
			return true;
	}
	return false;
}

bool MapManager::checkCollitionForBullet(RECT* _rc, DIRECTION _dir)
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		if ((*iter)->reduction(*_rc, _dir))
		{
			return true;
		}
	}
	return false;
}

void MapManager::changeDebugMode()
{
	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		(*iter)->chageMode();
	}
}
