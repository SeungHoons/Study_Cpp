#pragma once
#include<Windows.h>
#include<vector>
#include<fstream>

#define GAME_WINDOW_X_Y 13

enum RADION_BUTTON_ID
{
	R_B_1 = 3,
	R_B_2,
	R_B_3,
	R_B_4,
	R_B_5,
	R_B_6,
	R_B_7,
	R_B_8,
	R_B_9,
	R_B_10,
	R_B_11,
	R_B_12,
	R_B_13,
	R_B_14,
	R_B_END
};
class Bitmap;

struct S_TILE
{
	RECT rc;
	Bitmap* pBitmap;
	int resIndex;
};
class MapTool
{
	HWND m_hWnd;
	RECT m_buttonRect;
	Bitmap* m_selectBitmap;
	std::vector<S_TILE*> m_vecTile;
public:
	MapTool();
	~MapTool();

	void init(HWND _hWnd, HINSTANCE _hInst);
	void InputButton(WPARAM _wParam);
	void render(HDC _hdc);
	void update();

	void checkRect(int _x, int _y);
	void setObject(S_TILE* _pTile);

	void initTile();
	void reDo();
	void unDo();

	void saveFile();
	void loadFile();
};

