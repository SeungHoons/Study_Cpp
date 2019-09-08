#pragma once
#include "Scene.h"


#define MIN_X 0;
#define MAX_X 4000;
enum E_KEYSTATE
{
	KEYSTATE_LEFT,
	KEYSTATE_RIGHT,
	KEYSTATE_EMPTY
};

class Object;
class TileManager;
class Image;
class MoveObject;
class Character;
class MainScene : public Scene
{
	HWND m_hWnd;
	HDC m_memDC;
	HBITMAP m_memBitmap;
	vector<Object*> m_vecObject;
	TileManager* m_pTileManager;
	Image* m_pImageDark;

	Character* m_pCharacter;
	MoveObject* m_pFireRing;

	int m_iCameraPoint;
	E_KEYSTATE m_eKeyState;
public:
	MainScene();
	~MainScene();

	virtual void init(HDC _hdc, HWND _hWnd);
	virtual void input(UINT iMessage ,WPARAM _wParam);
	virtual void update();
	virtual void render(HDC _hdc);
	virtual void release();

	void setCamera();
};

