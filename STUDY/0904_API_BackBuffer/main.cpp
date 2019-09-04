#include <Windows.h>
#include <vector>
#include <math.h>
#include <utility>
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
void Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}
#define PI 3.141592f
float DegreToRadius(float degree)
{
	return (PI / 180)*degree;
}
void DrawCircle(HDC hdc, int x, int y, int xR, int xL)
{
	for (int i = 0; i <= 360; i++)
	{
		int _x = cosf(DegreToRadius(i))*xR + x;
		int _y = sinf(DegreToRadius(i))*xL + y;

		SetPixel(hdc, _x, _y, RGB(0, 0, 0));
	}
}
//struct POINT
//{
//	int x;
//	int y;
//};
HDC memDC[3];
HBITMAP hBitmap[3];
HBITMAP hOld[3];
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rt = { 100,100,400,300 };
	static int x;
	static int y;
	static BOOL bNowDraw = FALSE;
	static std::vector<std::pair<POINT, POINT>> vec;

	static TCHAR str[256];
	int len;
	switch (iMessage)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		SetTimer(hWnd, 1, 10, NULL);
		memDC[0] = CreateCompatibleDC(hdc);
		hBitmap[0] = CreateCompatibleBitmap(hdc, 1024, 768);
		hOld[0] = (HBITMAP)SelectObject(memDC[0], hBitmap[0]);

		memDC[1] = CreateCompatibleDC(memDC[0]);
		hBitmap[1] = (HBITMAP)LoadImage(NULL, "back.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		hOld[1] = (HBITMAP)SelectObject(memDC[1], hBitmap[1]);

		memDC[2] = CreateCompatibleDC(memDC[0]);
		hBitmap[2] = (HBITMAP)LoadImage(NULL, "cha.bmp", IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
		hOld[2] = (HBITMAP)SelectObject(memDC[2], hBitmap[2]);


		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_DOWN:
			y++;
			break;
		case VK_UP:
			y--;
			break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;
	case WM_TIMER:

		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		BitBlt(memDC[0], 0, 0, 1024, 768, memDC[1], 0, 0, SRCCOPY);
		TransparentBlt(memDC[0], x, y, 100, 107, memDC[2], 0, 0, 199, 214, RGB(255, 0, 255));

		BitBlt(hdc, 0, 0, 1024, 768, memDC[0], 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}