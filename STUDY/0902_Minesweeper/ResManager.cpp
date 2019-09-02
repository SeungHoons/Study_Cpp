#include "ResManager.h"
#include "BitMap.h"
//#include "resource.h"
#include "macro.h"
ResManager* ResManager::sThis = nullptr;


ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}

void ResManager::init(HDC _hdc, HINSTANCE _hInst)
{
	//for (int i = 0; i < RES_TYPE_END; i++)
	//{
	//	pBitMap[i] = new BitMap();
	//	pBitMap[i]->init(_hdc, _hInst, IDB_BITMAP1 + i);
	//}
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		pBitMap[i] = new BitMap();
	}

	pBitMap[RES_TYPE_BACK]->init(_hdc, _hInst, "./Resource/back.bmp");
	pBitMap[RES_TYPE_BLOCK]->init(_hdc, _hInst, "./Resource/block.bmp");
	pBitMap[RES_TYPE_BLOCK_00]->init(_hdc, _hInst, "./Resource/block_0.bmp");
	pBitMap[RES_TYPE_BLOCK_01]->init(_hdc, _hInst, "./Resource/block_1.bmp");
	pBitMap[RES_TYPE_BLOCK_02]->init(_hdc, _hInst, "./Resource/block_2.bmp");
	pBitMap[RES_TYPE_BLOCK_03]->init(_hdc, _hInst, "./Resource/block_3.bmp");
	pBitMap[RES_TYPE_BLOCK_04]->init(_hdc, _hInst, "./Resource/block_4.bmp");
	pBitMap[RES_TYPE_BLOCK_05]->init(_hdc, _hInst, "./Resource/block_5.bmp");
	pBitMap[RES_TYPE_BLOCK_06]->init(_hdc, _hInst, "./Resource/block_6.bmp");
	pBitMap[RES_TYPE_BLOCK_07]->init(_hdc, _hInst, "./Resource/block_7.bmp");
	pBitMap[RES_TYPE_BLOCK_08]->init(_hdc, _hInst, "./Resource/block_8.bmp");
	pBitMap[RES_TYPE_FLAG]->init(_hdc, _hInst, "./Resource/flag.bmp");
	pBitMap[RES_TYPE_MINE]->init(_hdc, _hInst, "./Resource/mine.bmp");
}

BitMap* ResManager::getBitMap(int index)
{
	//배열 검사

	return pBitMap[index];
}

void ResManager::release()
{
	for (int i = 0; i < RES_TYPE_END; i++)
	{
		SAFE_DELETE(pBitMap[i]);
	}
}
