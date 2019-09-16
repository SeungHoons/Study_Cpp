#include "Player.h"
#include "ResManager.h"
#include "BitMap.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::init()
{

	for (int i = 0; i < 4; i++)
	{
		m_pBitMap[i].resize(2);
	}

	m_pBitMap[0][0];
}
