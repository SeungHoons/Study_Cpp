#include "BitMap.h"



BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::init(HDC hdc, HINSTANCE hInst, std::string str)
{
	hMemDC = CreateCompatibleDC(hdc);
	//hBitMap = LoadBitmap(hInst, MAKEINTRESOURCE(id));
	//hBitMap = (HBITMAP)LoadImage(NULL, MAKEINTRESOURCE("id"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	//hBitMap = (HBITMAP)LoadImage(NULL, "./Resource/back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	hBitMap = (HBITMAP)LoadImage(NULL, str.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);

	BITMAP bitmap;
	GetObject(hBitMap, sizeof(bitmap), &bitmap);
	size.cx = bitmap.bmWidth;
	size.cy = bitmap.bmHeight;
}

void BitMap::draw(HDC hdc, int x, int y)
{
	BitBlt(hdc, x, y, size.cx, size.cy, hMemDC, 0, 0, SRCCOPY);
}

void BitMap::release()
{
	SelectObject(hMemDC, hOldBitMap);
	DeleteObject(hBitMap);
	DeleteDC(hMemDC);
}
