#pragma once
#include <Windows.h>
#include <string>
class BitMap
{
private:
	HDC hMemDC;
	HBITMAP hBitMap;
	HBITMAP hOldBitMap;
	SIZE size;
public:
	void init(HDC hdc, HINSTANCE hInst, std::string str);
	void draw(HDC hdc, int x, int y);
	void release();


	BitMap();
	~BitMap();
};

