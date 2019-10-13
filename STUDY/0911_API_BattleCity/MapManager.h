#pragma once
#include "Global.h"

class Tile;
class MapManager
{
	vector<Tile*> m_vecTile;
public:
	MapManager();
	~MapManager();


	void init();
	void update();
	void render(HDC _hdc);

	//�ݸ��� �ڽ� ����
	void setCollitionBox(int _index);

	//�浹 ó��
	bool checkColltion(RECT* _rc);
	bool checkCollitionForBullet(RECT* _rc, DIRECTION _dir);

	//debug
	void changeDebugMode();
};

