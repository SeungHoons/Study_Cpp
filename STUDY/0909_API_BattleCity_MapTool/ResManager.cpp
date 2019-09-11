#include "ResManager.h"
#include <string>
#include "Bitmap.h"
#include "macro.h"
ResManager* ResManager::Inst= nullptr;

ResManager::ResManager()
{
}


ResManager::~ResManager()
{
}


void ResManager::init(HDC _hdc)
{
	string str;
	char tempChar[128];


	for (int i = 0; i < FILE_NAME_END; i++)
	{
		m_pVecBitmap.push_back(new Bitmap());
	}

	for (int i = 0; i < FILE_TANK_RIGHT; i++)
	{
		str = "./Resource/block";
		//memset(&tempChar[0], 0, 2);
		itoa(i, tempChar, 10);
		if (i < 10)
		{
			str = str + "0" /*+ tempStr.c_str()*/;
			str = str + tempChar;
			str = str + ".bmp";
		}
		else
		{
			str = str + tempChar;
			str = str + ".bmp";
		}
		m_pVecBitmap[i]->init(_hdc, str.c_str(), i);
	}
	m_pVecBitmap[FILE_TANK_RIGHT]->init(_hdc, "./Resource/tank_right_00.bmp", FILE_TANK_RIGHT);
}

Bitmap * ResManager::getBitMap(RES_FILE_NAME fileName)
{
	return m_pVecBitmap[fileName];
}

void ResManager::release()
{
	for (int i = 0; i < m_pVecBitmap.size(); i++)
	{
		SAFE_DELETE(m_pVecBitmap[i]);
	}
	if (Inst)
	{
		delete Inst;
		Inst = nullptr;
	}
}

void ResManager::fileLoad(HWND _hWnd)
{
	OPENFILENAME OFN;

	char str[256];
	char lpstrFile[256] = "";

	memset(&OFN, 0, sizeof(OPENFILENAME));

	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = _hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0 TextFile\0*.txt*\0.ini\0";
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";
	if (GetOpenFileName(&OFN) != 0)
	{
		sprintf(str, "%s 파일을 선택했습니다. ", OFN.lpstrFile);
		MessageBox(_hWnd, str, "파일열기 성공", MB_OK);
	}
	else
	{
		MessageBox(_hWnd, ("파일 오픈 에러입니다."), ("파일열기실패"), MB_OK);
		return;
	}

	
}

void ResManager::fileSave(HWND _hWnd)
{
	OPENFILENAME OFN;

	char str[256];
	char lpstrFile[256] = "";

	memset(&OFN, 0, sizeof(OPENFILENAME));

	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = _hWnd;
	OFN.lpstrFilter = "Every File(*.*)\0*.*\0 TextFile\0*.txt*\0.ini\0";
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 256;
	OFN.lpstrInitialDir = "c:\\";
	if (GetSaveFileName(&OFN) != 0)
	{
		sprintf(str, "%s 파일을 저장했습니다. ", OFN.lpstrFile);
		MessageBox(_hWnd, str, "파일열기 성공", MB_OK);
	}
	else
	{
		MessageBox(_hWnd, ("파일 오픈 에러입니다."), ("파일열기실패"), MB_OK);
		return;
	}
}
