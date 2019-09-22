#include "MainScene.h"
#include "BlockManager.h"


MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}


void MainScene::init(HDC _hdc, HWND _hWnd)
{
	m_pBlockManager = new BlockManager();
	m_pBlockManager->init();
	m_backBuffer = CreateCompatibleDC(_hdc);
	m_hBitmap = CreateCompatibleBitmap(_hdc, 1024, 768);
	m_hOld = (HBITMAP)SelectObject(m_backBuffer, m_hBitmap);
}
void MainScene::input(UINT _iMessage, WPARAM _wParam)
{

}

void MainScene::update()
{

}

void MainScene::render(HDC _hdc)
{
	m_pBlockManager->render(m_backBuffer);

	BitBlt(_hdc, 0, 0, 1024, 768, m_backBuffer, 0, 0, SRCCOPY);
}
void MainScene::release()
{
	SelectObject(m_backBuffer, m_hOld);
	DeleteObject(m_hBitmap);
	DeleteDC(m_backBuffer);
}