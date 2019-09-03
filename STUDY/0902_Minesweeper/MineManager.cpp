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
	setBlockOfRandom(10);
	setBlockOfNormal();
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

	//pMineBox[15]->setBlock(STATE_TYPE_MINE);
	//pMineBox[16]->setBlock(STATE_TYPE_MINE);
	//pMineBox[17]->setBlock(STATE_TYPE_MINE);
	//pMineBox[18]->setBlock(STATE_TYPE_MINE);
	//pMineBox[20]->setBlock(STATE_TYPE_MINE);
	while (tempSet.size()<_MineNum)
	{
		tempSet.insert(rand() % pMineBox.size());
	}
	
	for (auto iter = tempSet.begin(); iter != tempSet.end(); iter++)
	{
		pMineBox[*iter]->setBlock(STATE_TYPE_MINE);
	}
	tempSet.clear();
}

void MineManager::setBlockOfNormal()
{
	int index;
	for (int i = 0; i < MINE_HEIGHT; i++)
	{
		for (int j = 0; j < MINE_WIDHT; j++)
		{
			index = (i*MINE_WIDHT) + j;
			if (pMineBox[index]->ischeckMine())
				continue;
			checkAreaOfBlock(index);
		}
	}
}

void MineManager::checkAreaOfBlock(int _index)
{
	int i_start, i_end;
	int j_start, j_end;
	int countMine=0;

	i_start = -1;
	j_start = -1;
	i_end = 1;
	j_end = 1;

	if ((_index / MINE_WIDHT) == 0)
	{
		i_start = 0;
		i_end = 1;
	}
	else if ((_index / MINE_WIDHT) == (MINE_HEIGHT - 1))
	{
		i_start = -1;
		i_end = 0;
	}

	if ((_index % MINE_WIDHT) == 0)
	{
		j_start = 0;
		j_end = 1;
	}
	else if ((_index % MINE_WIDHT) == (MINE_WIDHT - 1))
	{
		j_start = -1;
		j_end = 0;
	}

	int temp;
	for (int i = i_start; i <= i_end; i++)
	{
		for (int j = j_start; j <= j_end; j++)
		{
			temp = _index + (i*MINE_WIDHT) + j;
			if (pMineBox[temp]->ischeckMine())
			{
				countMine++;
			}
		}
	}
	pMineBox[_index]->setBlock((STATE_BOX)(countMine + 2));
}

void MineManager::opendBlock00(int _index)
{
	if (!pMineBox[_index]->isBlock00())
		return;
	int i_start, i_end;
	int j_start, j_end;

	i_start = -1;
	j_start = -1;
	i_end = 1;
	j_end = 1;

	if ((_index / MINE_WIDHT) == 0)
	{
		i_start = 0;
	}
	else if ((_index / MINE_WIDHT) == (MINE_HEIGHT - 1))
	{
		i_end = 0;
	}

	if ((_index % MINE_WIDHT) == 0)
	{
		j_start = 0;
	}
	else if ((_index % MINE_WIDHT) == (MINE_WIDHT - 1))
	{
		j_end = 0;
	}

	int temp;
	for (int i = i_start; i <= i_end; i++)
	{
		for (int j = j_start; j <= j_end; j++)
		{
			temp = _index + (i*MINE_WIDHT) + j;
			if (!pMineBox[temp]->ischeckMine())
			{
				if (!pMineBox[temp]->isOpend())
				{
					pMineBox[temp]->checkMine();
					opendBlock00(temp);
				}
			}
		}
	}
	return;
}

void MineManager::clickCheck(POINT _point)
{
	for (int i = 0; i < pMineBox.size(); i++)
	{
		if (pMineBox[i]->clickBox(_point))
		{
			if (!pMineBox[i]->isOpend())
			{
				clickOpend(i);
			}
			else
			{
				if (!pMineBox[i]->ischeckMine())
					opendBlock00(i);
			}			
		}
	}
}

void MineManager::clickOpend(int _index)
{
	//pMineBox[_index]
}

void MineManager::rbClickCheck(POINT _point)
{
	for (int i = 0; i < pMineBox.size(); i++)
	{
		if (pMineBox[i]->rbClickBox(_point))
		{
			if (pMineBox[i]->isOpend())
			{

			}
			else
			{
				pMineBox[i]->setFlag();
			}
		}
	}
}