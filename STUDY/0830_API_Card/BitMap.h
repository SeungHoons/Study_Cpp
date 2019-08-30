#pragma once
#include <Windows.h>

#define CARD_WIDTH 145
#define CARD_HEIGHT 235

class BitMap
{
private:
	HWND hWnd;
	HDC hMemDC;
	HBITMAP hBitMap;
	HBITMAP hOldBitMap;

public:
	BitMap();
	~BitMap();

	void init(HDC _hdc, HINSTANCE hInst, int id);
	void draw(HDC _hdc, int _x, int _y);
	void release();
};

