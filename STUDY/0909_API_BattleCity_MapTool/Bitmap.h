#pragma once
#include <Windows.h>
#include <string>

using namespace std;

class Bitmap
{
private:

	HDC		m_hMemDC;
	HBITMAP m_hBitMap;
	HBITMAP m_hOldBitMap;
	int m_index;
	SIZE m_size;


public:
	Bitmap();
	~Bitmap();

	void init(HDC _hdc, string _str, int _index);
	void render(HDC hdc, int x, int y);
	void render(HDC hdc, int x, int y, float multiply);
	void release();

	SIZE getSize() { return m_size; }
	int getIndex() { return m_index; }
};
