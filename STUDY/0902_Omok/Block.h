#pragma once
#include "Global.h"

class BitMap;
class Block
{
private:
	BitMap* m_bitMap[2];
	WHAT_BLOCK_STATE m_state;
	POINT m_position;


public:
	Block();
	~Block();

	void init();
	void update();
	void render(HDC _hdc);

};

