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
	vector<RECT> m_vecInRect;
	//RECT m_

	bool debugMode;
public:
	Tile();
	~Tile();

	void init(BitMap* _bitmap, RECT* _rect);
	void render(HDC _hdc);


	//debug
	void renderDebugCollitionBox(HDC _hdc);
	void chageMode();

	void setInRect(POINT _point);

	//colltion check
	bool checkColltion(RECT & _rc);

	//broke wall
	bool reduction(RECT& _rc, DIRECTION _dir);
};

