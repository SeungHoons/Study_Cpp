#include "MapTool.h"
#include "ResManager.h"
#include "Bitmap.h"
MapTool::MapTool()
{
}


MapTool::~MapTool()
{
}

void MapTool::init(HWND _hWnd, HINSTANCE _hInst)
{
	m_buttonRect = { 550,30,950,500 };
	m_hWnd = _hWnd;
	CreateWindow(TEXT("button"), TEXT("SAVE"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 700, 620, 100, 25, _hWnd, (HMENU)0, _hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("LOAD"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 850, 620, 100, 25, _hWnd, (HMENU)1, _hInst, NULL);
	CreateWindow(TEXT("button"), TEXT("BITMAP"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX, m_buttonRect.left, m_buttonRect.top, 400, 500, _hWnd, (HMENU)1, _hInst, NULL);
	CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 580, 60, 15, 25, _hWnd, (HMENU)3, _hInst, NULL);
	for (int i = 1; i < 14; i++)
	{
		if (i < 7)
		{
			CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 580, 60 + i * 63, 15, 25, _hWnd, (HMENU)(i + 3), _hInst, NULL);
		}
		else
		{
			CreateWindow(TEXT("button"), TEXT(""), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 580+190, 60 + (i-7) * 63, 15, 25, _hWnd, (HMENU)(i + 3), _hInst, NULL);
		}
	}
	CheckRadioButton(_hWnd, R_B_1, R_B_14, R_B_1);
}

void MapTool::InputButton(WPARAM _wParam)
{
	switch (LOWORD(_wParam))
	{
	case 0:
		ResManager::getInst()->fileSave(m_hWnd);
		//MessageBox(hWnd, TEXT("First Button Clicked"), TEXT("Button"), MB_OK);
		return;
	case 1:
		ResManager::getInst()->fileLoad(m_hWnd);
		//MessageBox(hWnd, TEXT("First Button Clicked"), TEXT("Button"), MB_OK);
		return;

	case R_B_1:		
	case R_B_2:
	case R_B_3:		
	case R_B_4:		
	case R_B_5:		
	case R_B_6:		
	case R_B_7:		
	case R_B_8:		
	case R_B_9:		
	case R_B_10:		
	case R_B_11:		
	case R_B_12:		
	case R_B_13:				
	case R_B_14:
		int index = LOWORD(_wParam) - 3;
		m_selectBitmap = ResManager::getInst()->getBitMap((RES_FILE_NAME)index);
		return;
		
	}
}

void MapTool::render(HDC _hdc)
{
	//타일 종류 그려주기
	for (int i = FILE_BLCOK00; i < FILE_BLOCK14; i++)
	{
		Bitmap* tempBitMap;
		if (i < 7)
		{
			tempBitMap = ResManager::getInst()->getBitMap((RES_FILE_NAME)i);
			tempBitMap->render(_hdc, 620, 60 + (i * 63), 1.5f);
		}
		else
		{
			tempBitMap = ResManager::getInst()->getBitMap((RES_FILE_NAME)i);
			tempBitMap->render(_hdc, 620+190, 60 + ((i-7) * 63), 1.5f);
		}
	}

	
}

void MapTool::initTile()
{
	for (int i = 0; i < GAME_WINDOW_X_Y; i++)
	{
		S_TILE* a = new S_TILE;
		//RECT tempRect = {0,0,;
		//a->rc = tempRect;
		//m_vecTile.push_back(a);
	}

}
