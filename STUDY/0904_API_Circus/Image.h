#pragma once
#include "Global.h"
class Image
{
private:
	HDC hMemDC;		
	HBITMAP hBit;	
	HBITMAP hOBit;	
	SIZE m_size;

public:
	Image();
	~Image();

	void init(HDC hdc);
	void render(HDC hdc, int x, int y, int cx, int cy);
	void release();

	SIZE getSize(){return m_size}
};

