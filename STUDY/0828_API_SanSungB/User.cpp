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

}

void User::print()
{
}

void User::update()
{
}

void User::input()
{
	
}

void User::setUserRect(RECT & rc)
{
	userRc.top = rc.bottom - 300;
	userRc.left = rc.right / 2;
	userRc.right = rc.right;
	userRc.bottom = rc.bottom;
}
