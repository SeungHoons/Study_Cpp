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

	case WM_LBUTTONDOWN:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		bNowDraw = TRUE;
		return 0;
	case WM_MOUSEMOVE:
		if (bNowDraw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, x, y, NULL);
			POINT a,f;
			a.x = x;
			a.y = y;
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			f.x = x;
			f.y = y;
			LineTo(hdc, x, y);
			//vec.push_back(std::pair<POINT, POINT>(a, f));
			vec.push_back(std::make_pair(a, f));
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP:
		bNowDraw = FALSE;
		return 0;
	/*case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			x -= 8;
			break;
		case VK_RIGHT:
			x += 8;
			break;
		case VK_UP:
			y -= 8;
			break;
		case VK_DOWN:
			y += 8;
			break;

		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;*/
	//case WM_CHAR:
	//	len = lstrlen(str);
	//	str[len] = (TCHAR)wParam;
	//	str[len + 1] = 0;
	//	InvalidateRect(hWnd, NULL, FALSE);
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 100, 100, str, lstrlen(str));
		for (int i = 0; i < vec.size(); i++)
		{
			MoveToEx(hdc, vec[i].first.x, vec[i].first.y ,NULL);
			LineTo(hdc, vec[i].second.x, vec[i].second.y);
		}
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}