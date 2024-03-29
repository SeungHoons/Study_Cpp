#include <Windows.h>
#include "SceneManager.h"
#include "ResManager.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("CIRCUS_ copyright _ Hoons");

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

	//hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
	//	CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	//	NULL, (HMENU)NULL, hInstance, NULL);
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

SceneManager* pSceneManager;
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;


	switch (iMessage)
	{
	case WM_CREATE:
		//콘솔 디버깅 사용을 위한 셋팅
		AllocConsole();
		freopen("CONOUT$", "wt", stdout);
		/////////////////////////////////////
		hdc = GetDC(hWnd);
		ResManager::getSingleton()->init(hdc);

		SceneManager::getSingleton()->init(hdc, hWnd);

		SetTimer(hWnd, 1, 10, NULL);
		return 0;

	case WM_TIMER:
		SceneManager::getSingleton()->update();
		//타이머가 엄청 빠르니까 출력하는것도 cpu 최대치로 출력할꺼임 프레임 제한 걸어주는거 생각해보기
		return 0;
	case WM_KEYUP:
	case WM_KEYDOWN:
		SceneManager::getSingleton()->input(iMessage ,wParam);
		//SceneManager::getSingleton()->
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		SceneManager::getSingleton()->render(hdc);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_DESTROY:
		SceneManager::getSingleton()->freeInst();
		SceneManager::getSingleton()->releaseSingleton();
		FreeConsole();
		PostQuitMessage(0);
		return 0;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}