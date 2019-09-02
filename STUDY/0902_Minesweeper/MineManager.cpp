#include "MineManager.h"
#include "MineBox.h"
#include "ResManager.h"
#include <time.h>



MineManager::MineManager()
{
}


MineManager::~MineManager()
{
}

void MineManager::init()
{
	srand(GetTickCount());
	startPoint.x = START_X;
	startPoint.y = START_Y;
	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		for(int j =0; j<MINE_WIDHT; j++)
		{
			pMineBox.push_back(new MineBox());
			pMineBox.back()->init(ResManager::GetInstance()->getSize(), j,i, startPoint);
		}
	}
	setBlockOfRandom(5);
}

void MineManager::draw(HDC _hdc)
{
	for (auto iter = pMineBox.begin(); iter != pMineBox.end(); iter++)
	{
		(*iter)->draw(_hdc);
	}
}

void MineManager::update()
{
}

void MineManager::setBlockOfRandom(int _MineNum)
{
	std::set<int> tempSet;

	while (tempSet.size()<_MineNum)
	{
		tempSet.insert(rand() % pMineBox.size());
	}
	
	for (auto iter = tempSet.begin(); iter != tempSet.end(); iter++)
	{
		pMineBox[*iter]->setBlock(STATE_TYPE_MINE);
	}
	tempSet.clear();
	//for (auto iter = pMineBox.begin(); iter != pMineBox.end(); iter++)
	//{
	//	(*iter)->setBlock()
	//}
}

void MineManager::clickCheck(POINT _point)
{
	for (auto iter = pMineBox.begin(); iter != pMineBox.end(); iter++)
	{
		(*iter)->clickBox(_point);
	}
}
