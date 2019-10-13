#pragma once
#include "Global.h"

class Bullet;
class BitMap;
class Player
{
private:
	chrono::system_clock::time_point m_LastTime;
	float m_fElapseTime;

	vector<BitMap*> m_pBitMap[4];
	float m_fCurAniamtionIndex;

	F_POSITION m_position;
	float m_speed;
	DIRECTION m_dir;
	bool m_bIsMove;
	RECT m_rectForCollitionCheck;

	//�̵��� ����
	float m_saveMove;

	vector<Bullet*> m_vecBullet;
	float m_fFireTime;
public:
	Player();
	~Player();

	void init();
	void update();
	void render(HDC _hdc);

	void isMove(DIRECTION _dir);
	void fire();
	
	//�ʰ� �ݸ��� üũ
	RECT* getRect();
	void backPosition();

	//�Ѿ� �ݸ��� üũ
	bool isBulletActive(int _index);
	RECT* getRectBullet(int _index);
	void unActiveBullet(int _index);
	DIRECTION getBulletDirection(int _index);
};

