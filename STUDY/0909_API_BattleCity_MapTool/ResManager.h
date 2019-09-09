#pragma once
#include <Windows.h>
#include <vector>
using namespace std;

enum RES_FILE_NAME
{
	FILE_BLCOK00,
	FILE_BLOCK01,
	FILE_BLCOK02,
	FILE_BLOCK03,
	FILE_BLCOK04,
	FILE_BLOCK05,
	FILE_BLCOK06,
	FILE_BLOCK07,
	FILE_BLCOK08,
	FILE_BLOCK09,
	FILE_BLCOK10,
	FILE_BLOCK11,
	FILE_BLCOK12,
	FILE_BLOCK13,
	FILE_BLOCK14,
	FILE_TANK_RIGHT,
	FILE_NAME_END
};

class Bitmap;
class ResManager
{
private:
	Bitmap* m_image;
	vector<Bitmap*> m_pVecBitmap;
public:
	ResManager();
	~ResManager();

	void init(HDC _hdc);
	Bitmap* getBitMap(RES_FILE_NAME fileName);
	void release();

	void fileLoad(HWND _hWnd);
	void fileSave(HWND _hWnd);
};

