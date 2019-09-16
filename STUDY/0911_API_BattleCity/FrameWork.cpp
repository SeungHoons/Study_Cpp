#include "FrameWork.h"
#include <math.h>
#include <stdio.h>
#include "ResManager.h"
#include "MapManager.h"

FrameWork::FrameWork()
{
	Player_x = 200.0f;
	Player_y = 500.0f;

	m_bJump = false;

	m_fVectorX = 1.0f;
	m_fVectorY = 0.0f;

	m_LastTime = std::chrono::system_clock::now();
}

FrameWork::~FrameWork()
{
}

void FrameWork::Init(HWND hWnd)
{
	m_hWnd = hWnd;
	HDC hdc = GetDC(hWnd);
	ResManager::getInst()->init(GetDC(hWnd));
	ResManager::getInst()->fileLoad(hWnd);

	m_pMapManger = new MapManager;
	m_pMapManger->init();
	
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

	Render();
}

void FrameWork::OperateInput()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
		Player_x -= 500 * m_fElapseTime;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		Player_x += 500 * m_fElapseTime;
	if (GetKeyState(VK_UP) & 0x8000)
		Player_y -= 500 * m_fElapseTime;
	if (GetKeyState(VK_DOWN) & 0x8000)
		Player_y += 500 * m_fElapseTime;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (m_bJump == false)
		{
			// 키 다운
			m_bJump = true;

		}
		else
		{
			//누르고 있을때
		}
	}
	else
	{
		if (m_bJump)
		{
			//키 업
		}
		m_bJump = false;

	}

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


	BitBlt(hdc, 0, 0, 700, 600, m_hMemDC[0], 0, 0, SRCCOPY);

	ReleaseDC(m_hWnd, hdc);
}
