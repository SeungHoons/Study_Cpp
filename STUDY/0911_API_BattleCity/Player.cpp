#include "Player.h"
#include "ResManager.h"
#include "BitMap.h"
#include "Bullet.h"


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

	m_pBitMap[DIRECTION::DIR_UP][0] = ResManager::getInst()->getBitMap(FILE_TANK_UP_00);
	m_pBitMap[DIRECTION::DIR_UP][1] = ResManager::getInst()->getBitMap(FILE_TANK_UP_01);
	m_pBitMap[DIRECTION::DIR_DOWN][0] = ResManager::getInst()->getBitMap(FILE_TANK_DOWN_00);
	m_pBitMap[DIRECTION::DIR_DOWN][1] = ResManager::getInst()->getBitMap(FILE_TANK_DOWN_01);
	m_pBitMap[DIRECTION::DIR_LEFT][0] = ResManager::getInst()->getBitMap(FILE_TANK_LEFT_00);
	m_pBitMap[DIRECTION::DIR_LEFT][1] = ResManager::getInst()->getBitMap(FILE_TANK_LEFT_01);
	m_pBitMap[DIRECTION::DIR_RIGHT][0] = ResManager::getInst()->getBitMap(FILE_TANK_RIGHT_00);
	m_pBitMap[DIRECTION::DIR_RIGHT][1] = ResManager::getInst()->getBitMap(FILE_TANK_RIGHT_01);
	
	m_dir = DIR_UP;
	m_position.x = 400;
	m_position.y = 400;
	m_bIsMove = false;
	m_fCurAniamtionIndex = 0.0f;
	m_speed = 100;

	//ÃÑ¾Ë
	for (int i = 0; i < 3; i++)
	{
		//»ý¼º ÇßÀ½ Áö¿öÁà¾ßÇÔ.
		m_vecBullet.push_back(new Bullet());
		m_vecBullet[i]->init();
	}
	m_fFireTime = 0.0f;
}

void Player::update()
{
	std::chrono::duration<float> sec = std::chrono::system_clock::now() - m_LastTime;

	if (sec.count() < (1 / FPS))
		return;
	m_fElapseTime = sec.count();
	m_LastTime = std::chrono::system_clock::now();

	//ÃÑ¾Ë °ü·Ã
	for (int i = 0; i < m_vecBullet.size(); i++)
	{
		if (m_vecBullet[i]->isActive())
		{
			m_vecBullet[i]->move(m_fElapseTime);
		}
	}
	m_fFireTime += (m_fElapseTime * 3);
	
	if (m_bIsMove)
	{
		switch (m_dir)
		{
		case DIR_UP:
			m_position.y -= (m_fElapseTime * m_speed);
			break;
		case DIR_DOWN:
			m_position.y += (m_fElapseTime * m_speed);
			break;
		case DIR_LEFT:
 			m_position.x -= (m_fElapseTime * m_speed);
			break;
		case DIR_RIGHT:
			m_position.x += (m_fElapseTime * m_speed);
			break;
		default:
			break;
		}

		m_fCurAniamtionIndex += m_fElapseTime * 15;
		if (m_fCurAniamtionIndex > 2)
		{
			m_fCurAniamtionIndex = 0;
		}
	}
	m_bIsMove = false;
}

void Player::render(HDC _hdc)
{
	int index =  m_fCurAniamtionIndex;
	m_pBitMap[m_dir][index]->render(_hdc, m_position.x, m_position.y,TILE_SIZE,TILE_SIZE);

	for (int i = 0; i < m_vecBullet.size(); i++)
	{
		if (m_vecBullet[i]->isActive())
		{
			m_vecBullet[i]->render(_hdc);
		}
	}
}

void Player::isMove(DIRECTION _dir)
{
	m_dir = _dir;
	m_bIsMove = true;
}

void Player::fire()
{
	if (m_fFireTime > 1)
	{
		for (auto iter = m_vecBullet.begin(); iter != m_vecBullet.end(); iter++)
		{
			if ((*iter)->isActive())
				continue;
			(*iter)->fire(m_position.x+20, m_position.y+20, m_dir);
			break;
		}
		m_fFireTime = 0.0f;
	}
}
