#include "ResouceManager.h"
#include "BitMap.h"



ResouceManager::ResouceManager()
{
}


ResouceManager::~ResouceManager()
{
}

void ResouceManager::init(HDC _hdc, HINSTANCE _hInst, HWND _hWnd)
{
	for (int i = 0; i < RES_BITMAP_END; i++)
	{
		hBitMap.push_back(new BitMap());
		
	}
	for (int i = 0; i < 11; i++)
	{
		hBitMap[i]->init(_hdc, _hInst, 101 + i);
	}
}
