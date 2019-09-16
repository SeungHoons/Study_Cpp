#pragma once
#include "Global.h"


class BitMap;
class Player
{
private:
	POINT m_position;
	vector<BitMap*> m_pBitMap[4];
	DIRECTION m_dir;
public:
	Player();
	~Player();

	void init();
};

