#pragma once
#include <Windows.h>

enum RES_TYPE
{
	RES_TYPE_BACK,
	RES_TYPE_BLOCK,
	RES_TYPE_BLOCK_00,
	RES_TYPE_BLOCK_01,
	RES_TYPE_BLOCK_02,
	RES_TYPE_BLOCK_03,
	RES_TYPE_BLOCK_04,
	RES_TYPE_BLOCK_05,
	RES_TYPE_BLOCK_06,
	RES_TYPE_BLOCK_07,
	RES_TYPE_BLOCK_08,
	RES_TYPE_FLAG,
	RES_TYPE_MINE,
	RES_TYPE_END
};

#define IMAGE_FILE 13
class BitMap;
class ResManager
{
private:
	static ResManager* sThis;

	BitMap* pBitMap[RES_TYPE_END];
	ResManager();
	
public:
	static ResManager* GetInstance()
	{
		if (sThis == nullptr)
			sThis = new ResManager();

		return sThis;
	}
	void init(HDC _hdc, HINSTANCE _hInst);
	BitMap* getBitMap(int index);
	void release();

	int getSize() { return RES_TYPE_END; }

	~ResManager();
};

