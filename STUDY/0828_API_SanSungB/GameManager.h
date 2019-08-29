#pragma once
#include "Global.h"

class RainManager;
class User;
class KeyManager;
class GameManager
{
private:
	RainManager* pRainManager;
	User* pUser;
	int score;

public:
	GameManager();
	~GameManager();

	void init(HWND hWnd);
	void input(WPARAM wParam);
	void print(HDC hdc);
	void update();

	void correctStr();
};

