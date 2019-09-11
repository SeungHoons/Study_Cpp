#include "Bitmap.h"
#include <assert.h>


Bitmap::Bitmap()
{
}


Bitmap::~Bitmap()
{
}

void Bitmap::init(HDC _hdc, string _str, int _index)
{
	m_hMemDC = CreateCompatibleDC(_hdc);
	m_hBitMap = (HBITMAP)LoadImage(NULL, _str.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	if (m_hBitMap == 0)
	{
		assert(0);
	}
	m_hOldBitMap = (HBITMAP)SelectObject(m_hMemDC, m_hBitMap);

	BITMAP bitmap;
	GetObject(m_hBitMap, sizeof(bitmap), &bitmap);
	m_size.cx = bitmap.bmWidth;
	m_size.cy = bitmap.bmHeight;
	m_index = _index;
}

void Bitmap::render(HDC hdc, int x, int y)
{
	BitBlt(hdc, x, y, m_size.cx, m_size.cy, m_hMemDC, 0, 0, SRCCOPY);
}

void Bitmap::render(HDC hdc, int x, int y, float multiply)
{
	TransparentBlt(hdc, x, y, m_size.cx * multiply, m_size.cy * multiply, m_hMemDC, 0, 0, m_size.cx, m_size.cy, RGB(255, 0, 255));
}

void Bitmap::release()
{
	SelectObject(m_hMemDC, m_hOldBitMap);
	DeleteObject(m_hBitMap);
	DeleteDC(m_hMemDC);
}


