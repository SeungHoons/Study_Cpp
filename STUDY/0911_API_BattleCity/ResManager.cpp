#include "ResManager.h"
#include <string>
#include "BitMap.h"
#include "macro.h"

ResManager* ResManager::Inst = nullptr;

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

	//담을 백터 초기화
	for (int i = 0; i < FILE_NAME_END; i++)
	{
		m_pVecBitmap.push_back(new BitMap());
	}
	//m_pVecBitmap.resize(FILE_NAME_END); //공간만 잡음

	//블록 불러오기
	for (int i = 0; i <= FILE_BLOCK14; i++)
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

	//
	str = "./Resource/";
	m_pVecBitmap[FILE_E_DOWN_00]->init(_hdc, str + "e_down_00.bmp");
	m_pVecBitmap[FILE_E_DOWN_01]->init(_hdc, str + "e_down_01.bmp");
	m_pVecBitmap[FILE_E_LEFT_00]->init(_hdc, str + "e_left_00.bmp");
	m_pVecBitmap[FILE_E_LEFT_01]->init(_hdc, str + "e_left_01.bmp");
	m_pVecBitmap[FILE_E_UP_00]->init(_hdc, str + "e_up_00.bmp");
	m_pVecBitmap[FILE_E_UP_01]->init(_hdc, str + "e_up_01.bmp");
	m_pVecBitmap[FILE_E_RIGHT_00]->init(_hdc, str + "e_RIGHT_00.bmp");
	m_pVecBitmap[FILE_E_RIGHT_01]->init(_hdc, str + "e_RIGHT_01.bmp");
	m_pVecBitmap[FILE_TANK_DOWN_00 ]->init(_hdc, str + "tank_down_00.bmp");
	m_pVecBitmap[FILE_TANK_DOWN_01 ]->init(_hdc, str + "tank_down_01.bmp");
	m_pVecBitmap[FILE_TANK_LEFT_00 ]->init(_hdc, str + "tank_left_00.bmp");
	m_pVecBitmap[FILE_TANK_LEFT_01]->init(_hdc, str + "tank_left_01.bmp");
	m_pVecBitmap[FILE_TANK_UP_00]->init(_hdc, str + "tank_UP_00.bmp");
	m_pVecBitmap[FILE_TANK_UP_01 ]->init(_hdc, str + "tank_UP_01.bmp");
	m_pVecBitmap[FILE_TANK_RIGHT_00 ]->init(_hdc, str + "tank_right_00.bmp");
	m_pVecBitmap[FILE_TANK_RIGHT_01]->init(_hdc, str + "tank_right_01.bmp");

	m_pVecBitmap[FILE_MISSILE_00 ]->init(_hdc, str + "missile_00.bmp");
	m_pVecBitmap[FINE_EXPLOSION_00 ]->init(_hdc, str + "explosion_00.bmp");
	m_pVecBitmap[FILE_EXPLOSION_01 ]->init(_hdc, str + "explosion_01.bmp");
	m_pVecBitmap[FILE_EXPLOSION_02 ]->init(_hdc, str + "explosion_02.bmp");
	m_pVecBitmap[FILE_EXPLOSION_03 ]->init(_hdc, str + "explosion_03.bmp");
	m_pVecBitmap[FILE_EXPLOSION_04 ]->init(_hdc, str + "explosion_04.bmp");
	m_pVecBitmap[FILE_ICON_PLYAER ]->init(_hdc, str + "player_icon.bmp");
	m_pVecBitmap[FILE_ICON_ENEMY ]->init(_hdc, str + "enemy_icon.bmp");
	m_pVecBitmap[FILE_ICON_STAGE ]->init(_hdc, str + "stage_icon.bmp");
	
	m_vecMapLoad.resize(13 * 13);

}

BitMap * ResManager::getBitMap(RES_FILE_NAME fileName)
{
	return m_pVecBitmap[fileName];
}

BitMap * ResManager::getLoadBitMap(int _index)
{
	if (m_vecMapLoad[_index] == -1)
		return nullptr;
	else
		return m_pVecBitmap[m_vecMapLoad[_index]];
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
	char str[256];

	string dd = "./Map/stage1.txt";

	std::ifstream ofname(dd);

	auto iter = m_vecMapLoad.begin();

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			ofname >> (*iter);
			iter++;
		}
	}
	ofname.close();
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
