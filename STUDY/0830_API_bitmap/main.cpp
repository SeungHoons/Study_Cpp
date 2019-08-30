#include <Windows.h>
#include "resource.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("first");

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
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

HDC hMemDC;
HBITMAP hBitMap;
HBITMAP hOldBitMap;

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t  mytime;
	static HANDLE hTimer;
	static const char *str;
	static POINT point;
	static int count = 1;
	static int y = -1;
	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		hTimer = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
		hMemDC = CreateCompatibleDC(hdc);
		hBitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		hOldBitMap = (HBITMAP)SelectObject(hMemDC, hBitMap);
		ReleaseDC(hWnd, hdc);
		point.x=0; 
		point.y=0;
		return 0;
	case WM_TIMER:
		if(count %5==0)
		{
			point.y += 80;
			point.x = 0;
		}
		if (count % 10 == 0)
		{
			point.y -= 80;
			count = 1;
			point.x = 0;
		}
		point.x += 80;
		count++;
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		BitBlt(hdc, 100, 100, 80, 80, hMemDC, point.x, point.y , SRCCOPY);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		SelectObject(hMemDC, hOldBitMap);
		DeleteObject(hBitMap);
		DeleteDC(hMemDC);
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}