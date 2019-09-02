#pragma once
#include <vector>

#define MINE_WIDHT 10
#define MINE_HEIGHT 7

class MineBox;
class MineManager
{
private:
	std::vector<MineBox*> pMineBox;
public:
	MineManager();
	~MineManager();

	void init();
};

