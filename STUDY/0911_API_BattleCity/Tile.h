#pragma once
#include "Global.h"


enum ATTRIBUTE
{
	WALL,
	HIDE,
	EMPTY
};
class BitMap;

class Tile
{
	BitMap* m_pBitmap;
	RECT m_rect;
	RECT m_inRect[4];
public:
	Tile();
	~Tile();

	void init(BitMap* _bitmap, RECT* _rect);
	void render(HDC _hdc);
};

