
#include "GameManager.h"
#include "RainManager.h"
#include "User.h"
#include "KeyManager.h"

GameManager::GameManager()
{
	pRainManager = new RainManager();
	pUser = new User();
}


GameManager::~GameManager()
{
}

void GameManager::init(HWND hWnd)
{
	pRainManager->init(hWnd);
	pUser->init(hWnd);
}

void GameManager::input(WPARAM wParam)
{
	pUser->input(wParam);
}

void GameManager::print(HDC hdc)
{
	pUser->print(hdc);
	pRainManager->print(hdc);
}

void GameManager::update()
{
	pUser->update();
	pRainManager->update();
}

void GameManager::correctStr()
{

}
