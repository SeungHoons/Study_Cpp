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
	m_pBitMap = ResManager::getInst()->getBitMap(RES_FILE_NAME::RES_FILE_BACK_GROUND);
	for (int i = 0; i < CHECKER_BOARD_XY; i++)
	{
		for (int j = 0; j < CHECKER_BOARD_XY; j++)
		{
			m_vecBlock.push_back(new Block());
			m_vecBlock.back()->init();
		}
	}
}

void BlockManager::update()
{
}

void BlockManager::render(HDC _hdc)
{
	m_pBitMap->render(_hdc,0,0);
	for (auto iter = m_vecBlock.begin(); iter != m_vecBlock.end(); iter++)
	{
		(*iter)->render(_hdc);
	}
}
