#pragma once
#include "Global.h"

class BitMap;
class Block;
class BlockManager
{
private:
	BitMap* m_pBitMap;
	//vector<Block*> m_vecBlock;
	Block* m_pBlock[CHECKER_BOARD_XY][CHECKER_BOARD_XY];
	WHAT_BLOCK_STATE m_nowPlayer;
public:
	BlockManager();
	~BlockManager();

	void init();
	void update();
	void render(HDC _hdc);

	void checkCollition(POINT _pt);
	void checkFiveStone(int _y, int _x);
};

