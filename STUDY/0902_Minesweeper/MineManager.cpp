#include "MineManager.h"
#include "MineBox.h"
#include "ResManager.h"


MineManager::MineManager()
{
}


MineManager::~MineManager()
{
}

void MineManager::init()
{
	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		for(int j =0; j<MINE_WIDHT; j++)
		{
			pMineBox.push_back(new MineBox());
			pMineBox.back()->init(ResManager::GetInstance()->getSize());
		}
	}
}
