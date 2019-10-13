#include "FrameWork.h"
#include <math.h>
#include <stdio.h>
#include "ResManager.h"
#include "MapManager.h"
#include "Player.h"

FrameWork::FrameWork()
{
	m_LastTime = std::chrono::system_clock::now();
}

FrameWork::~FrameWork()
{
}

void FrameWork::Init(HWND hWnd)
{
	m_clickedKeyD = false;

	m_hWnd = hWnd;
	HDC hdc = GetDC(hWnd);
	ResManager::getInst()->init(GetDC(hWnd));
	ResManager::getInst()->fileLoad(hWnd);

	m_pMapManger = new MapManager;
	m_pMapManger->init();
	m_pPlayer = new Player;
	m_pPlayer->init();
	
	m_hMemDC[0] = CreateCompatibleDC(hdc);
	m_hBitmap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_hOld[0] = (HBITMAP)SelectObject(m_hMemDC[0], m_hBitmap[0]);

	m_hMemDC[1] = CreateCompatibleDC(m_hMemDC[0]);
	m_hBitmap[1] = (HBITMAP)LoadImage(NULL, "./Resource/Back_Gray2.bmp", IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOld[1] = (HBITMAP)SelectObject(m_hMemDC[1], m_hBitmap[1]);

	m_hMemDC[2] = CreateCompatibleDC(m_hMemDC[0]);
	m_hBitmap[2] = (HBITMAP)LoadImage(NULL, "./Resource/Back_Dark2.bmp", IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_hOld[2] = (HBITMAP)SelectObject(m_hMemDC[2], m_hBitmap[2]);
	ReleaseDC(hWnd, hdc);
}


void FrameWork::Release()
{
	for (int i = 0; i < 3; i++)
	{
		SelectObject(m_hMemDC[i], m_hOld[i]);
		DeleteObject(m_hBitmap[i]);
		DeleteDC(m_hMemDC[i]);
	}

}

#define PI 3.141592f

void FrameWork::Update()
{

	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{
		POINT pt;
		GetCursorPos(&pt);

		ScreenToClient(m_hWnd, &pt);
	}

	std::chrono::duration<float> sec = std::chrono::system_clock::now() - m_LastTime;
	/*if (sec.count() < (1 / FPS))
		return;*/
	m_fElapseTime = sec.count();
	m_LastTime = std::chrono::system_clock::now();


	OperateInput();

	m_pPlayer->update();

	//벽이랑 플레이어 충돌 체크
	if (m_pMapManger->checkColltion(m_pPlayer->getRect()))
	{
		m_pPlayer->backPosition();
	}

	//총알 벽 충돌체크 
	for (int i = 0; i < 3; i++)
	{
		if (m_pPlayer->isBulletActive(i))
		{
			if (m_pMapManger->checkCollitionForBullet(m_pPlayer->getRectBullet(i), m_pPlayer->getBulletDirection(i)))
			{
				//트루면 맵매니저에서 
				m_pPlayer->unActiveBullet(i);
			}
		}
	}
	Render();
}

void FrameWork::OperateInput()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
		m_pPlayer->isMove(DIR_LEFT);
	
	if (GetKeyState(VK_RIGHT) & 0x8000)
		m_pPlayer->isMove(DIR_RIGHT);

	if (GetKeyState(VK_UP) & 0x8000)
		m_pPlayer->isMove(DIR_UP);

	if (GetKeyState(VK_DOWN) & 0x8000)
		m_pPlayer->isMove(DIR_DOWN);


	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		m_pPlayer->fire();
	}

	if (GetKeyState('D') & 0x8000)
	{
		if (!m_clickedKeyD)
		{
			m_pMapManger->changeDebugMode();
		}
		m_clickedKeyD = true;
	}
	else
		m_clickedKeyD = false;

}

void FrameWork::Render()
{
	HDC hdc = GetDC(m_hWnd);

	//BitBlt(m_hMemDC[0], 0, 0, 1024, 768, m_hMemDC[1], 0, 0, SRCCOPY);
	//BackGround
	TransparentBlt(m_hMemDC[0], 0, 0, 700, 600, m_hMemDC[1], 0, 0, 100, 100, RGB(255, 0, 255));
	TransparentBlt(m_hMemDC[0], TILE_START_POINT_X, TILE_START_POINT_Y, 520, 520, m_hMemDC[2], 0, 0, 100, 100, RGB(255, 0, 255));
	///////////////////////////////////
	
	m_pMapManger->render(m_hMemDC[0]);
	m_pPlayer->render(m_hMemDC[0]);

	BitBlt(hdc, 0, 0, 700, 600, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, hdc);
}
