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

	//콜리전 박스 세팅
	void setCollitionBox(int _index);

	//충돌 처리
	bool checkColltion(RECT* _rc);
	bool checkCollitionForBullet(RECT* _rc, DIRECTION _dir);

	//debug
	void changeDebugMode();
};

