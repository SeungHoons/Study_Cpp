#pragma once
#include<Windows.h>
#include<vector>

class BitMap;
class MineBox
{
private:
	std::vector<BitMap*> pBitMap;
	POINT point;

public:
	MineBox();
	~MineBox();

	void init(int _num);
};

