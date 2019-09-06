#pragma once
#include "Scene.h"

class Object;
class Tile;
class MainScene : public Scene
{
	HWND m_hWnd;
	HDC m_memDC;
	vector<Object*> m_vecObject;
	vector<Tile*> m_vecTile;
public:
	MainScene();
	~MainScene();

	virtual void init(HWND _hWnd);
	virtual void input(WPARAM _wParam);
	virtual void update();
	virtual void render(HDC _hdc);
	virtual void release();
};

