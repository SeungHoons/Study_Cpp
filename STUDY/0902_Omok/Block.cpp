#include "Block.h"
#include "ResManager.h"
#include "BitMap.h"



Block::Block()
{
}


Block::~Block()
{
}

void Block::init()
{
	m_bitMap[BLACK_STONE] = ResManager::getInst()->getBitMap(RES_FILE_BLACK_STONE);
	m_bitMap[WHITE_STONE] = ResManager::getInst()->getBitMap(RES_FILE_WHITE_STONE);
	m_state = BLOCK_EMPTY;

}

void Block::update()
{
}

void Block::render(HDC _hdc)
{
	if (m_state != BLOCK_EMPTY)
	{
		m_bitMap[m_state]->render(_hdc, m_position.x, m_position.y);
	}
}