#include <Windows.h>
#include <vector>
#include <math.h>
#include <utility>
#include <time.h>
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

void collision(HWND _hWnd, POINT &p1, POINT &p2)
{

}
//struct POINT
//{
//	int x;
//	int y;
//};

#define BALL_SIZE 50
#define USER_SIZE 20
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	time_t  mytime;
	static HANDLE hTimer;
	static POINT point;
	static POINT userPoint;
	static int userSpeed;
	static bool up;
	static bool left;
	RECT clientRC;
	static int b;
	switch (iMessage)
	{
	case WM_CREATE:
		hTimer = (HANDLE)SetTimer(hWnd, 1, 10, NULL);
		GetClientRect(hWnd, &clientRC);
		point.x = 300;
		point.y = 300;

		userPoint.x = 100;
		userPoint.y = 100;
		userSpeed = 5;
		up = false;
		left = false;
		return 0;

	case WM_TIMER:
		time(&mytime);
		GetClientRect(hWnd, &clientRC);
		b = log(pow((userPoint.x - point.x), 2) + pow((userPoint.y - point.y), 2));
		if (70 >= log(pow((userPoint.x - point.x), 2) + pow((userPoint.y - point.y), 2)))
		{
			KillTimer(hWnd, 1);
			MessageBoxA(hWnd, "³¡", "³¡", FALSE);
			SendMessage(hWnd, WM_DESTROY, wParam, lParam);
		}
		//collision(hWnd, point, userPoint);
		if (up)
		{
			point.y-=5;
		}
		else
		{
			point.y+= 5;
		}

		if (left)
		{
			point.x-= 5;
		}
		else
		{
			point.x+= 5;
		}


		if (clientRC.left > point.x - BALL_SIZE)
			left = false;
		if (clientRC.right < point.x + BALL_SIZE)
			left = true;
		if (clientRC.top > point.y - BALL_SIZE)
			up = false;
		if (clientRC.bottom < point.y + BALL_SIZE)
			up = true;


		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Ellipse(hdc, userPoint.x - USER_SIZE, userPoint.y - USER_SIZE, userPoint.x + USER_SIZE, userPoint.y + USER_SIZE);
		Ellipse(hdc, point.x - BALL_SIZE, point.y - BALL_SIZE, point.x + BALL_SIZE, point.y + BALL_SIZE);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			userPoint.x -= userSpeed;
			break;
		case VK_RIGHT:
			userPoint.x += userSpeed;
			break;
		case VK_UP:
			userPoint.y -= userSpeed;
			break;
		case VK_DOWN:
			userPoint.y += userSpeed;
			break;
		default:
			break;
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}