#include <Windows.h>
#include <assert.h>

#include <vector>
#include <math.h>
#include <utility>
#include "ResManager.h"
#include "Bitmap.h"
#include "MapTool.h"

using namespace std;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Maptool Of BattleCity_ copyright _ Hoons");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstace, LPSTR lpszCmpParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}
#define ID_EDIT 100
HWND hEdit;
MapTool g_mapTool;

HDC g_MemDC[2];
HBITMAP g_BitMap[2];
HBITMAP g_OldBitMap[2];


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[128];

	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		//hEdit = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, 10, 10, 200, 25, hWnd, (HMENU)ID_EDIT, g_hInst, NULL);

		ResManager::getInst()->init(hdc);
		g_mapTool.init(hWnd, g_hInst);

		g_MemDC[0] = CreateCompatibleDC(hdc);
		g_BitMap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
		g_OldBitMap[0] = (HBITMAP)SelectObject(g_MemDC[0], g_BitMap[0]);

		g_MemDC[1] = CreateCompatibleDC(g_MemDC[0]);
		g_BitMap[1] = (HBITMAP)LoadImage(NULL, "./Resource/Back_Dark.bmp", IMAGE_BITMAP, 0,0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		g_OldBitMap[1] = (HBITMAP)SelectObject(g_MemDC[1], g_BitMap[1]);

		if(g_BitMap[1] == NULL)
		{
			assert(0);
		}

		return 0;

	case WM_COMMAND:
		//switch (LOWORD(wParam))
		//{
		//case ID_EDIT:
		//	switch (HIWORD(wParam))
		//	{
		//	case EN_CHANGE:
		//		GetWindowText(hEdit, str, 128);
		//		SetWindowText(hWnd, str);
		//	}
		//}
		//return 0;

		g_mapTool.InputButton(wParam);
		
		return 0;


	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//backGround 그려주기//////////////////////////////////////////////////////////////////////////////////////
		BitBlt(g_MemDC[0], 0, 0, 1024, 768, g_MemDC[1], 0, 0, SRCCOPY);
		TransparentBlt(g_MemDC[0], 0, 0, 500, 500, g_MemDC[1], 0, 0, 429, 326, RGB(255, 0, 255));
		//Rectangle(g_MemDC[0], g_buttonRect.left, g_buttonRect.top, g_buttonRect.right, g_buttonRect.bottom);
		//////////////////////////////////////////////////////////////////////////////////////

		//객체 그려주기
		g_mapTool.render(g_MemDC[0]);


		//빽버퍼 윈도우 해당 버퍼에 그려주기
		BitBlt(hdc, 0, 0, 1024, 768, g_MemDC[0], 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}