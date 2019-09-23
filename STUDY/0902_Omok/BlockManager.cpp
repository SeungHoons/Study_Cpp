#include "BlockManager.h"
#include "Block.h"
#include "ResManager.h"
#include "BitMap.h"

BlockManager::BlockManager()
{
}


BlockManager::~BlockManager()
{
}

void BlockManager::init()
{
	m_nowPlayer = BLACK_STONE;
	m_pBitMap = ResManager::getInst()->getBitMap(RES_FILE_NAME::RES_FILE_BACK_GROUND);

	float tem_x;
	float tem_y;
	for (int i = 0; i < CHECKER_BOARD_XY; i++)
	{
		for (int j = 0; j < CHECKER_BOARD_XY; j++)
		{
			tem_x = j * 37.5;
			tem_y = i * 37.5;

			m_pBlock[i][j] = new Block();
			m_pBlock[i][j]->init((tem_x)+BLCOK_START_POINT_X, (tem_y)+BLOCK_START_POINT_Y);

			/*m_vecBlock.push_back(new Block());
			m_vecBlock.back()->init((tem_x) + BLCOK_START_POINT_X, (tem_y)+BLOCK_START_POINT_Y);*/
			
		}
	}
}

void BlockManager::update()
{
}

void BlockManager::render(HDC _hdc)
{
	m_pBitMap->render(_hdc,0,0);
	for (int i = 0; i < CHECKER_BOARD_XY; i++)
	{
		for (int j = 0; j < CHECKER_BOARD_XY; j++)
		{
			m_pBlock[i][j]->render(_hdc);
		}
	}

	//for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	//{
	//	(*iter)->render(_hdc);
	//}
}

void BlockManager::checkCollition(POINT _pt)
{
	for (int i = 0; i < CHECKER_BOARD_XY; i++)
	{
		for (int j = 0; j < CHECKER_BOARD_XY; j++)
		{
			if (m_pBlock[i][j]->collision(_pt))
			{
				if (m_pBlock[i][j]->isEmpty())
				{
					m_pBlock[i][j]->setStone(m_nowPlayer);
					checkFiveStone(i, j);

					if (m_nowPlayer == BLACK_STONE)
						m_nowPlayer = WHITE_STONE;
					else
						m_nowPlayer = BLACK_STONE;
				}
			}
		}
	}


	//for (int i= 0; i< m_vecBlock.size(); i++)
	//{
	//	if (m_vecBlock[i]->collision(_pt))
	//	{
	//		if (m_vecBlock[i]->isEmpty())
	//		{
	//			m_vecBlock[i]->setStone(m_nowPlayer);
	//			checkFiveStone(i);

	//			if (m_nowPlayer == BLACK_STONE)
	//				m_nowPlayer = WHITE_STONE;
	//			else
	//				m_nowPlayer = BLACK_STONE;
	//		}
	//	}
	//}
}

void BlockManager::checkFiveStone(int _y, int _x)
{
	int count = 0;
	int minX = _x - 4;
	int maxX = _x + 5;
	int minY = _y - 4;
	int maxY = _y + 5;

	if (minX < 0)
		minX = 0;
	if (maxX >= CHECKER_BOARD_XY)
		maxX = CHECKER_BOARD_XY - 1;
	if (minY < 0)
		minY = 0;
	if (maxY >= CHECKER_BOARD_XY)
		maxY = CHECKER_BOARD_XY - 1;

	bool win[4];		// 가로 세로 대각선*2

	//가로
	for (int i = minX; i < maxX; i++)
	{
		if (m_pBlock[_y][i]->whatState() == m_nowPlayer)
		{
			count++;
		}
		else
			count = 0;

		if (count == 5)
			win[0] = true;
		if (count > 5)
			win[0] = false;
	}

	//세로
	for (int i = minY; i < maxY; i++)
	{
		if (m_pBlock[i][_x]->whatState() == m_nowPlayer)
		{
			count++;
		}
		else
			count = 0;

		if (count == 5)
			win[1] = true;
		if (count > 5)
			win[1] = false;
	}

	//대각선 위아래


	int i;
	int j;
	if()
	for ( i= minY; i < maxY; i++)
	{
		j = minX; 
		if (m_pBlock[i][j]->whatState() == m_nowPlayer)
		{
			count++;
		}
		else
			count = 0;

		if (count == 5)
			win[1] = true;
		if (count > 5)
			win[1] = false;
		j++;
	}
}
