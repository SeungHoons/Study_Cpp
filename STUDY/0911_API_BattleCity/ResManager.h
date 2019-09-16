#pragma once
#include <Windows.h>
#include <vector>
#include<fstream>

using namespace std;

enum RES_FILE_NAME
{
	FILE_BLCOK00,
	FILE_BLOCK01,
	FILE_BLCOK02,
	FILE_BLOCK03,
	FILE_BLCOK04,
	FILE_BLOCK05,
	FILE_BLCOK06,
	FILE_BLOCK07,
	FILE_BLCOK08,
	FILE_BLOCK09,
	FILE_BLCOK10,
	FILE_BLOCK11,
	FILE_BLCOK12,
	FILE_BLOCK13,
	FILE_BLOCK14,
	FILE_E_DOWN_00,
	FILE_E_DOWN_01,
	FILE_E_LEFT_00,
	FILE_E_LEFT_01,
	FILE_E_UP_00,
	FILE_E_UP_01,
	FILE_E_RIGHT_00,
	FILE_E_RIGHT_01,
	FILE_TANK_DOWN_00,
	FILE_TANK_DOWN_01,
	FILE_TANK_LEFT_00,
	FILE_TANK_LEFT_01,
	FILE_TANK_UP_00,
	FILE_TANK_UP_01,
	FILE_TANK_RIGHT_00,
	FILE_TANK_RIGHT_01,
	FILE_MISSILE_00,
	FINE_EXPLOSION_00,
	FILE_EXPLOSION_01,
	FILE_EXPLOSION_02,
	FILE_EXPLOSION_03,
	FILE_EXPLOSION_04,
	FILE_ICON_PLYAER,
	FILE_ICON_ENEMY,
	FILE_ICON_STAGE,
	FILE_NAME_END
};

class BitMap;
class ResManager
{
private:
	static ResManager* Inst;
	BitMap* m_image;
	vector<BitMap*> m_pVecBitmap;
	vector<int> m_vecMapLoad;
	ResManager();
	~ResManager();
public:
	static ResManager* getInst()
	{
		if (!Inst)Inst = new ResManager;
		return Inst;
	}
	void release();


	void init(HDC _hdc);
	BitMap* getBitMap(RES_FILE_NAME fileName);
	BitMap* getLoadBitMap(int _index);

	void fileLoad(HWND _hWnd);
	void fileSave(HWND _hWnd);
};

