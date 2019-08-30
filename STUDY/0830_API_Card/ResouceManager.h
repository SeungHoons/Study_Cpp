#pragma once
#include<Windows.h>
#include<vector>

enum RES_BITMAP_ID
{
	RES_BITMAP_00,
	RES_BITMAP_01,
	RES_BITMAP_02,
	RES_BITMAP_03,
	RES_BITMAP_04,
	RES_BITMAP_05,
	RES_BITMAP_06,
	RES_BITMAP_07,
	RES_BITMAP_08,
	RES_BITMAP_09,
	RES_BITMAP_BACK,
	RES_BITMAP_END
};
class BitMap;
class ResouceManager
{
private:
	std::vector<BitMap*> hBitMap;
	HWND hWnd;

public:
	ResouceManager();
	~ResouceManager();

	void init(HDC _hdc, HINSTANCE _hInst, HWND _hWnd);
};

