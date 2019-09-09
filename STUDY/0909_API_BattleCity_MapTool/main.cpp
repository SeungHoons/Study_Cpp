#include <Windows.h>
#include <vector>
#include <math.h>
#include <utility>
#include "ResManager.h"
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
ResManager g_resManager;
RECT g_mainScreenRect;
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
		g_mainScreenRect = { 0,0, 429,325 };
		g_resManager.init(hdc);
		CreateWindow(TEXT("button"), TEXT("SAVE"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 700, 620, 100, 25, hWnd, (HMENU)0, g_hInst, NULL);
		CreateWindow(TEXT("button"), TEXT("LOAD"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 850, 620, 100, 25, hWnd, (HMENU)1, g_hInst, NULL);
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

		switch (LOWORD(wParam))
		{
		case 0:
			g_resManager.fileSave(hWnd);
			//MessageBox(hWnd, TEXT("First Button Clicked"), TEXT("Button"), MB_OK);
			return 0;
		case 1:
			g_resManager.fileLoad(hWnd);
			//MessageBox(hWnd, TEXT("First Button Clicked"), TEXT("Button"), MB_OK);
			return 0;
		}
		return 0;


	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, g_mainScreenRect.left, g_mainScreenRect.top, g_mainScreenRect.right, g_mainScreenRect.bottom);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}