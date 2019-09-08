#pragma once
#include "Global.h"
class Image
{
private:
	HDC m_hMemDC;		
	HBITMAP m_hBitMap;	
	HBITMAP m_hOBitMap;	
	SIZE m_size;

public:
	Image();
	~Image();

	void init(HDC _hdc, string _str);
	void render(HDC hdc, int x, int y);
	void render(HDC hdc, int x, int y, float multiply);
	void release();

	SIZE getSize() { return m_size; }
};

