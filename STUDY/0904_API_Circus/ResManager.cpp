#include "ResManager.h"
#include "Image.h"

ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}

void ResManager::init(HDC _hdc)
{
	m_pVecBitmap.resize(FILE_NAME_END);

	m_pVecBitmap[FILE_BACK]->init(_hdc, "./Resource/back.bmp");
	m_pVecBitmap[FILE_BACK_DEKO]->init(_hdc, "./Resource/back_deco.bmp");
	m_pVecBitmap[FILE_BACK_NORMAL]->init(_hdc, "./Resource/back_normal.bmp");
	m_pVecBitmap[FILE_BACK_NORMAL2]->init(_hdc, "./Resource/back_normal2.bmp");
	m_pVecBitmap[FILE_BACK_MITER]->init(_hdc, "./Resource/miter.bmp");
	m_pVecBitmap[FILE_CHARACTER_DIE]->init(_hdc, "./Resource/die.bmp");
	m_pVecBitmap[FILE_CHARACTER_IDLE_0]->init(_hdc, "./Resource/player0.bmp");
	m_pVecBitmap[FILE_CHARACTER_IDLE_1]->init(_hdc, "./Resource/player1.bmp");
	m_pVecBitmap[FILE_CHARACTER_IDLE_2]->init(_hdc, "./Resource/player2.bmp");
	m_pVecBitmap[FILE_CHARACTER_WIN]->init(_hdc, "./Resource/win.bmp");
	m_pVecBitmap[FILE_CHARACTER_WIN2]->init(_hdc, "./Resource/win2.bmp");
	m_pVecBitmap[FILE_OBJECT_END]->init(_hdc, "./Resource/end.bmp");
	m_pVecBitmap[FILE_OBJECT_CASH]->init(_hdc, "./Resource/cash.bmp");
	m_pVecBitmap[FILE_ICON]->init(_hdc, "./Resource/icon.bmp");
	m_pVecBitmap[FILE_ICON_STAR1]->init(_hdc, "./Resource/star.bmp");
	m_pVecBitmap[FILE_ICON_STAR2]->init(_hdc, "./Resource/star1.bmp");
	m_pVecBitmap[FILE_ICON_STAR3]->init(_hdc, "./Resource/star2.bmp");
	m_pVecBitmap[FILE_ENEMY_CUP1]->init(_hdc, "./Resource/front.bmp");
	m_pVecBitmap[FILE_ENEMY_CUP2]->init(_hdc, "./Resource/front2.bmp");
	m_pVecBitmap[FILE_ENEMY_RING_ALL1]->init(_hdc, "./Resource/enemy.bmp");
	m_pVecBitmap[FILE_ENEMY_RING_ALL2]->init(_hdc, "./Resource/enemy1.bmp");
	m_pVecBitmap[FILE_ENEMY_RING_HALF1]->init(_hdc, "./Resource/enemy_f.bmp");
	m_pVecBitmap[FILE_ENEMY_RING_HALF2]->init(_hdc, "./Resource/enemy_1f.bmp");
}

HBITMAP ResManager::getBitMap(FILE_NAME fileName)
{
	return HBITMAP();
}

void ResManager::release()
{
	for (int i = 0; i < m_pVecBitmap.size(); i++)
	{
		SAFE_DELETE(m_pVecBitmap[i]);
	}
}