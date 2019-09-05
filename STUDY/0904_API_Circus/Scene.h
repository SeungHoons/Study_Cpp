#pragma once
#include "Global.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void init(HWND _hWnd);
	virtual void input(WPARAM _wParam);
	virtual void update();
	virtual void render(HDC _hdc);
	virtual void release();
};

