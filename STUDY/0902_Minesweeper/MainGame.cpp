#include "MainGame.h"
#include "ResManager.h"
#include "BitMap.h"
#include "MineManager.h"


MainGame* MainGame::sThis = nullptr;

MainGame::MainGame()
{
	//pResManager = new ResManager();
	pMineManager = new MineManager();
}

void MainGame::init(HWND _hWnd, HDC _hdc, HINSTANCE _hInst)
{
	hWnd = _hWnd;
	ResManager::GetInstance()->init(_hdc, _hInst);
	hBitmap = ResManager::GetInstance()->getBitMap(RES_TYPE_BACK);
	pMineManager->init();
	//pResManager->init(_hdc, _hInst);
	//hBitmap = pResManager->getBitMap(RES_TYPE_BACK);
}

void MainGame::draw(HDC hdc)
{
	hBitmap->draw(hdc, 0, 0);
	pMineManager->draw(hdc);
}

void MainGame::update()
{
}

void MainGame::input(POINT pt)
{
	pMineManager->clickCheck(pt);
}

void MainGame::release()
{
}

MainGame::~MainGame()
{
}


