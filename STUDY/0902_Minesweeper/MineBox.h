#pragma once
#include<Windows.h>
#include<vector>

enum STATE_BOX
{
	STATE_TYPE_BLOCK=1,
	STATE_TYPE_BLOCK_00,
	STATE_TYPE_BLOCK_01,
	STATE_TYPE_BLOCK_02,
	STATE_TYPE_BLOCK_03,
	STATE_TYPE_BLOCK_04,
	STATE_TYPE_BLOCK_05,
	STATE_TYPE_BLOCK_06,
	STATE_TYPE_BLOCK_07,
	STATE_TYPE_BLOCK_08,
	STATE_TYPE_FLAG,
	STATE_TYPE_MINE,
	STATE_TYPE_END
};
class BitMap;
class MineBox
{
private:
	std::vector<BitMap*> pBitMap;
	//RECT rc;
	POINT point;
	POINT startPoint;
	STATE_BOX nowState;
	STATE_BOX inState;
	bool isOpen;
public:
	MineBox();
	~MineBox();

	void init(int _num, int _x, int _y, POINT _start);
	void draw(HDC _hdc);
	void setBlock(STATE_BOX _state);
	void clickBox(POINT _point);
	void checkMine();
};

