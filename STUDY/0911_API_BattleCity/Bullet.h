#pragma once
#include "Global.h"

class BitMap;
class Bullet
{
	DIRECTION m_dir;
	BitMap* m_pBitMap[4];
	F_POSITION m_fPosition;
	bool m_bActive;
	float m_fSpeed;
	RECT m_rect;
public:
	Bullet();
	~Bullet();

	void init();
	void move(float sec);
	void render(HDC _hdc);
	void fire(int _x, int _y, DIRECTION _dir);

	bool isActive() { return m_bActive; }

	void unAcitve() { m_bActive = false; }

	RECT* getRect();
	DIRECTION getDirection() { return m_dir; }
	
	//void setActive();
};

