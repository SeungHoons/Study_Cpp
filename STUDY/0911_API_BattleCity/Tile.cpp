#include "Tile.h"
#include "BitMap.h"


Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::init(BitMap* _bitmap, RECT* _rect)
{
	m_rect = *_rect;
	m_pBitmap = _bitmap;
}

void Tile::render(HDC _hdc)
{
	if(m_pBitmap != nullptr)
		m_pBitmap->render(_hdc, m_rect.left+ TILE_START_POINT_X, m_rect.top+ TILE_START_POINT_Y, TILE_SIZE, TILE_SIZE);
}
