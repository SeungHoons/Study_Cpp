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
	for (int i = 1; i < 15; i++)
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
	initTile();
	m_selectBitmap = ResManager::getInst()->getBitMap(FILE_BLCOK00);
}

void MapTool::InputButton(WPARAM _wParam)
{
	int index;
	switch (LOWORD(_wParam))
	{
	case 0:
		//ResManager::getInst()->fileSave(m_hWnd);
		saveFile();
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
		index = LOWORD(_wParam) - 3;
		m_selectBitmap = ResManager::getInst()->getBitMap((RES_FILE_NAME)index);
		return;
	case R_B_END:
		m_selectBitmap = NULL;

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

	for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	{
		if ((*iter)->resIndex >-1)
		{
			(*iter)->pBitmap->render(_hdc, (*iter)->rc.left, (*iter)->rc.top);
		}
	}
	
}

void MapTool::update()
{
	InvalidateRect(m_hWnd, NULL, false);
}

void MapTool::checkRect(int _x, int _y)
{
	POINT tempP = { _x, _y };
	RECT tempRc;
	//for (auto iter = m_vecTile.begin(); iter != m_vecTile.end(); iter++)
	//{
	//	//tempRc = (*iter)->rc;
	//	if (PtInRect(&(*iter)->rc, tempP))
	//	{
	//		setObject((*iter));
	//	}
	//}

	for (int i = 0; i < m_vecTile.size(); i++)
	{
		//tempRc = (*iter)->rc;
		if (PtInRect(&(m_vecTile[i])->rc, tempP))
		{
			setObject(m_vecTile[i]);
		}
	}
}

void MapTool::setObject(S_TILE* _pTile)
{
	if (m_selectBitmap != NULL)
	{
		_pTile->pBitmap = m_selectBitmap;
		_pTile->resIndex = m_selectBitmap->getIndex();
	}
	else
	{
		_pTile->pBitmap = m_selectBitmap;
		_pTile->resIndex = -1;
	}
}

void MapTool::initTile()
{
	for (int i = 0; i < GAME_WINDOW_X_Y; i++)
	{
		for (int j = 0; j < GAME_WINDOW_X_Y; j++)
		{

			S_TILE* a = new S_TILE;
			RECT tempRect = { 40 * j ,40 * i,(40 * j)+40, (40 * i) + 40 };
			a->rc = tempRect;
			a->resIndex = -1;
			m_vecTile.push_back(a);
		}
	}
}

void MapTool::reDo()
{
}

void MapTool::unDo()
{
}

void MapTool::saveFile()
{
	OPENFILENAME OFN;

	char str[256];
	char lpstrFile[256] = "";

	memset(&OFN, 0, sizeof(OPENFILENAME));

	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = m_hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0 TextFile(*.txt*)\0*.txt*\0.ini\0";
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";
	if (GetSaveFileName(&OFN) != 0)
	{
		string dd = OFN.lpstrFile;
		dd += ".txt";
		std::ofstream ofname(dd);

		auto iter = m_vecTile.begin();

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				ofname << (*iter)->resIndex << " ";
				iter++;
			}
			ofname << endl;
		}
		ofname.close();
		sprintf(str, "%s 파일을 저장했습니다. ", OFN.lpstrFile);
		MessageBox(m_hWnd, str, "파일열기 성공", MB_OK);
	}
	else
	{
		MessageBox(m_hWnd, ("파일 오픈 에러입니다."), ("파일열기실패"), MB_OK);
		return;
	}

	
}

void MapTool::loadFile()
{
	OPENFILENAME OFN;

	char str[256];
	char lpstrFile[256] = "";

	memset(&OFN, 0, sizeof(OPENFILENAME));

	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = m_hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0 TextFile\0*.txt*\0.ini\0";
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";
	if (GetOpenFileName(&OFN) != 0)
	{
		sprintf(str, "%s 파일을 선택했습니다. ", OFN.lpstrFile);
		MessageBox(m_hWnd, str, "파일열기 성공", MB_OK);
	}
	else
	{
		MessageBox(m_hWnd, ("파일 오픈 에러입니다."), ("파일열기실패"), MB_OK);
		return;
	}
}
