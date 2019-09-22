#pragma once
#include "Global.h"

class BitMap;
class Block;
class BlockManager
{
private:
	BitMap* m_pBitMap;
	vector<Block*> m_vecBlock;
public:
	BlockManager();
	~BlockManager();

	void init();
	void update();
	void render(HDC _hdc);
};

