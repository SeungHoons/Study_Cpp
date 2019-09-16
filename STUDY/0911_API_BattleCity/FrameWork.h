#pragma once
#include "Global.h"

#define FPS			60.0f

enum STATE
{
	IDLE,
	MOVE,
	JUMP
};

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

	float		Player_x;
	float		Player_y;

	bool		m_bJump;
	//수학적으로
	STATE		m_eState;
	float		m_fJumpX;
	float		m_fJumpY;
	float		m_fCurJumpTime;

	//물리적
	float		m_fVectorX;
	float		m_fVectorY;
public:
	FrameWork();
	~FrameWork();

	void Init(HWND hWnd);
	void Release();
	void Update();
	void OperateInput();
	void Render();

};

