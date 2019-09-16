#pragma once
#include "Global.h"

class BitMap;

class Tile
{
	BitMap* m_pBitmap;
	RECT m_rect;
	
public:
	Tile();
	~Tile();

	void init(BitMap* _bitmap, RECT* _rect);
	void render(HDC _hdc);
};

