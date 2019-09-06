#pragma once
#include "Global.h"
#include "SingletoneBase.h"

enum FILE_NAME
{
	FILE_BACK,
	FILE_BACK_DEKO,
	FILE_BACK_NORMAL,
	FILE_BACK_NORMAL2,
	FILE_BACK_MITER,
	FILE_CHARACTER_DIE,
	FILE_CHARACTER_IDLE_0,
	FILE_CHARACTER_IDLE_1,
	FILE_CHARACTER_IDLE_2,
	FILE_CHARACTER_WIN,
	FILE_CHARACTER_WIN2,
	FILE_OBJECT_END,
	FILE_OBJECT_CASH,
	FILE_ICON,
	FILE_ICON_STAR1,
	FILE_ICON_STAR2,
	FILE_ICON_STAR3,
	FILE_ENEMY_CUP1,
	FILE_ENEMY_CUP2,
	FILE_ENEMY_RING_ALL1,
	FILE_ENEMY_RING_ALL2,
	FILE_ENEMY_RING_HALF1,
	FILE_ENEMY_RING_HALF2,
	FILE_NAME_END
};
class Image;
class ResManager : public singletonBase<ResManager>
{
	Image* m_image;
	vector<Image*> m_pVecBitmap;

public:
	ResManager();
	~ResManager();

	void init(HDC _hdc);
	HBITMAP getBitMap(FILE_NAME fileName);
	void release();
};

