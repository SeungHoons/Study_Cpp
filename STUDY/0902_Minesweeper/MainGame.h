#pragma once
#include <Windows.h>

class BitMap;
class MineManager;
class MainGame
{
private:
	static MainGame* sThis;
	//ResManager* pResManager;
	MineManager* pMineManager;
	BitMap* hBitmap;
	HWND hWnd;

	MainGame();
public:
	static MainGame* GetInstance()
	{
		if (sThis == nullptr)
			sThis = new MainGame();

		return sThis;
	}


	void init(HWND _hWnd, HDC _hdc, HINSTANCE _hInst);
	void draw(HDC hdc);
	void update();
	void input(POINT pt);

	void release();
	~MainGame();
};

