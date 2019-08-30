#include "BitMap.h"

BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::init(HDC _hdc, HINSTANCE hInst, int id)
{
	hMemDC = CreateCompatibleDC(_hdc);
	hBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(id));
	hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
}

void BitMap::draw(HDC _hdc, int _x, int _y)
{
	BitBlt(_hdc, _x, _y, CARD_WIDTH, CARD_HEIGHT,hMemDC, CARD_WIDTH, CARD_HEIGHT, SRCCOPY);
}

void BitMap::release()
{
	SelectObject(hMemDC, hOldBitMap);
	DeleteObject(hBitMap);
	DeleteDC(hMemDC);
}
