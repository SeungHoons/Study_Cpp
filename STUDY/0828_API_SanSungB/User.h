#pragma once
#include "Global.h"

class User
{
private:
	RECT userRc;
	TCHAR str[256];
	int len;

public:
	User();
	~User();

	void init(HWND _hWnd);
	void print(HDC hdc);
	void update();
	void input(WPARAM wParam);
	void enterKey();
	void setUserRect(RECT &rc);
};

