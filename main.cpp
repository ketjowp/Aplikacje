#include <windows.h>
#include <ctime>
#include <list>
#include "klocek.h"
#include "paletka.h"
#include "pilka.h"
#include "resource.h"
#include <dos.h>
TCHAR AppName[] = "Arkanoid";

std::list <Klocek> klocek;
std::list <Klocek>::iterator it;
Paletka paletka;
Pilka pilka;
RECT r;
HBRUSH brush = static_cast<HBRUSH>(GetStockObject(DC_BRUSH));
HDC hdcMem;
HBITMAP hbmMem;
HANDLE hbmOld;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: {
		GetClientRect(hwnd, &r);
		for (int i = 0; i < 40; i++)
		{
			if (i<10)
				klocek.push_back(Klocek(30 + i * 80, 100, 20, 10, FALSE));
			if (i >= 10 && i <20)
				klocek.push_back(Klocek(30 + (i - 10) * 80, 150, 20, 10, FALSE));
			if (i >= 20 && i <30)
				klocek.push_back(Klocek(30 + (i - 20) * 80, 200, 20, 10, FALSE));
			if (i >= 30 && i<40)
				klocek.push_back(Klocek(30 + (i - 30) * 80, 250, 20, 10, FALSE));
		}
		
		SetTimer(hwnd, 1, 16, NULL);
	}break;
	case WM_PAINT: {
		PAINTSTRUCT ps;

		GetClientRect(hwnd, &r);
		BeginPaint(hwnd, &ps);

		hdcMem = CreateCompatibleDC(ps.hdc);
		hbmMem = CreateCompatibleBitmap(ps.hdc, r.right, r.bottom);
		hbmOld = SelectObject(hdcMem, hbmMem);
		SetDCBrushColor(ps.hdc, BLACK_BRUSH);
		FillRect(hdcMem, &r, brush);

		for (it = klocek.begin(); it != klocek.end(); ++it)
			it->Rysujklocka(hdcMem, hwnd);
		BitBlt(ps.hdc, r.left, r.top, r.right, r.bottom, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, hbmOld);
		DeleteObject(hbmMem);
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);

	}break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return (DefWindowProc(hwnd, message, wParam, lParam));

	}
	return (0L);
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow)
	{
		srand(time(nullptr));
		MSG msg = { 0 };
		WNDCLASS wndclass;			
		HWND hwnd;
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = WindowProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInstance;
		wndclass.hIcon = NULL;
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = AppName;

		if (RegisterClass(&wndclass) == 0)
			return FALSE;

		hwnd = CreateWindowEx(WS_EX_WINDOWEDGE, AppName, AppName, WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^WS_MAXIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

		if (hwnd == NULL)
			return FALSE;

		ShowWindow(hwnd, SW_SHOW);
		UpdateWindow(hwnd);

		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{

			}
		}

		return static_cast<int>(msg.wParam);
	}