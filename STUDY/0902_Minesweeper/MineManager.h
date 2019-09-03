#pragma once
#include <Windows.h>
#include <vector>
#include <set>

#define MINE_WIDHT 10
#define MINE_HEIGHT 7
#define START_X 50
#define START_Y 100

class MineBox;
class MineManager
{
private:
	std::vector<MineBox*> pMineBox;
	POINT startPoint;
public:
	MineManager();
	~MineManager();

	void init();
	void draw(HDC _hdc);
	void update();

	void setBlockOfRandom(int _MineNum);
	void setBlockOfNormal();
	void checkAreaOfBlock(int _index);
	void opendBlock00(int _index);
	void clickCheck(POINT _point);
	void rbClickCheck(POINT _point);
	void clickOpend(int _index);
	
};

