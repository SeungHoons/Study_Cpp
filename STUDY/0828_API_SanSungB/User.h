#pragma once
#include <Windows.h>
class User
{
private:
	RECT userRc;

public:
	User();
	~User();

	void init(HWND _hWnd);
	void print();
	void update();
	void input();

	void setUserRect(RECT &rc);
};

