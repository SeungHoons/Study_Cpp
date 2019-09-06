#include "Image.h"
#include<cassert>


Image::Image()
{
}


Image::~Image()
{
}

void Image::init(HDC _hdc , string _str)
{
	m_hMemDC = CreateCompatibleDC(_hdc);

	
	m_hBitMap = (HBITMAP)LoadImage(NULL, _str.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	if (m_hBitMap == NULL)
	{
		assert(0);
	}
	m_hOBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

	BITMAP bitmap;
	GetObject(m_hBitMap, sizeof(bitmap), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
}

void Image::render(HDC hdc, int x, int y)
{
	BitBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
}

void Image::release()
{
	SelectObject(m_hMemDC, m_hOBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}
