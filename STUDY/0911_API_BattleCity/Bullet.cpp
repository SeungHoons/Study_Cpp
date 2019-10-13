#include "Bullet.h"
#include "ResManager.h"
#include "BitMap.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::init()
{
	m_fSpeed = 300;
	m_pBitMap[DIR_DOWN] = ResManager::getInst()->getBitMap(FILE_MISSILE_DOWN);
	m_pBitMap[DIR_UP] = ResManager::getInst()->getBitMap(FILE_MISSILE_UP);
	m_pBitMap[DIR_LEFT] = ResManager::getInst()->getBitMap(FILE_MISSILE_LEFT);
	m_pBitMap[DIR_RIGHT] = ResManager::getInst()->getBitMap(FILE_MISSILE_RIGHT);
	m_bActive = false;
}

void Bullet::move(float sec)
{
	switch (m_dir)
	{
	case DIR_UP:
		m_fPosition.y -= (m_fSpeed * sec);
		break;
	case DIR_DOWN:
		m_fPosition.y += (m_fSpeed * sec);
		break;
	case DIR_LEFT:
		m_fPosition.x -= (m_fSpeed * sec);
		break;
	case DIR_RIGHT:
		m_fPosition.x += (m_fSpeed * sec);
		break;
	default:
		break;
	}
	m_rect = { (int)m_fPosition.x,(int)m_fPosition.y,
		(int)(m_fPosition.x + m_pBitMap[m_dir]->getSize().cx),
		(int)(m_fPosition.y + m_pBitMap[m_dir]->getSize().cy) };

	if (m_fPosition.x < TILE_START_POINT_X || m_fPosition.x > TILE_START_POINT_X+520)
	{
		m_bActive = false;
	}
	else if (m_fPosition.y < TILE_START_POINT_Y || m_fPosition.y > TILE_START_POINT_Y + 520)
	{
		m_bActive = false;
	}
}

void Bullet::render(HDC _hdc)
{
	m_pBitMap[m_dir]->render(_hdc, m_fPosition.x, m_fPosition.y);
}

void Bullet::fire(int _x, int _y, DIRECTION _dir)
{
	m_dir = _dir;
	m_bActive = true;
	m_fPosition.x = _x - (m_pBitMap[m_dir]->getSize().cx) / 2;
	m_fPosition.y = _y - (m_pBitMap[m_dir]->getSize().cy) / 2;
	m_rect = { (int)m_fPosition.x,(int)m_fPosition.y,
		(int)(m_fPosition.x + m_pBitMap[m_dir]->getSize().cx),
		(int)(m_fPosition.y + m_pBitMap[m_dir]->getSize().cy) };
}

RECT* Bullet::getRect()
{
	return &m_rect;
}
