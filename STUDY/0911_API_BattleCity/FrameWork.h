#pragma once
#include "Global.h"

#define FPS			60.0f

enum STATE
{
	IDLE,
	MOVE,
	JUMP
};

class Player;
class MapManager;
class FrameWork
{
private:
	HWND		m_hWnd;
	chrono::system_clock::time_point m_LastTime;
	float		m_fElapseTime;

	HDC			m_hMemDC[3];
	HBITMAP		m_hBitmap[3];	//0 Back 1 BackGround 2 char
	HBITMAP		m_hOld[3];
	
	MapManager* m_pMapManger;
	Player*		m_pPlayer;

	//Å¬¸¯
	bool		m_clickedKeyD;
public:
	FrameWork();
	~FrameWork();

	void Init(HWND hWnd);
	void Release();
	void Update();
	void OperateInput();
	void Render();

};

