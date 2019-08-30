#include "User.h"
#include "KeyManager.h"


User::User()
{
	
}


User::~User()
{
}

void User::init(HWND _hWnd)
{
	RECT tempRc;
	GetClientRect(_hWnd, &tempRc);
	setUserRect(tempRc);
	memset(str, 0, 256);
	score = 0;
}

void User::print(HDC hdc)
{
	Rectangle(hdc, userRc.left - 20, userRc.top -20, userRc.right, userRc.bottom);
	TextOut(hdc, userRc.left, userRc.top, str, len);
}

void User::update()
{
}

void User::input(WPARAM wParam)
{
	if (((TCHAR)wParam) == '\r')
	{
		enterKey();
	}
	if (((TCHAR)wParam) == '\b')
	{
		str[len - 1] = 0;
	}
	len = lstrlen(str);
	str[len] = (TCHAR)wParam;
	str[len + 1] = 0;
}

void User::enterKey()
{
	memset(str, NULL, len);
}

void User::setUserRect(RECT & rc)
{
	userRc.top = rc.bottom - 100;
	userRc.left = (rc.right / 2)- 50;
	userRc.right = userRc.left + 100;
	userRc.bottom = userRc.top + 50;
}

void User::upScore()
{
	enterKey();
	score += 100;
}
