#include <windows.h>
#include <ctime>
#include <list>
#include "resource.h"
#include "zderzenia.h"

TCHAR AppName[] = "Arkanoid";

using namespace std;
std::list <Klocek> klocek;
std::list <Klocek>::iterator it;
Paletka paletka;
Pilka pilka;
RECT r;
HBRUSH brush = HBRUSH(CreateSolidBrush(RGB(255,255,255)));
HDC hdcMem;
HBITMAP hbmMem;
HANDLE hbmOld;
HWND hwnd;


LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: 
	{
		GetClientRect(hwnd, &r);
		
		for (int i = 0; i < 40; i++)
		{
			if (i<10)
				klocek.push_back(Klocek(0.05*r.right + i * 0.1*r.right, 100, 20, 10, FALSE));
			if (i >= 10 && i <20)
				klocek.push_back(Klocek(0.05*r.right + (i - 10) *0.1*r.right, 150, 20, 10, FALSE));
			if (i >= 20 && i <30)
				klocek.push_back(Klocek(0.05*r.right + (i - 20) * 0.1*r.right, 200, 20, 10, FALSE));
			if (i >= 30 && i<40)
				klocek.push_back(Klocek(0.05*r.right + (i - 30) * 0.1*r.right, 250, 20, 10, FALSE));
		}

		paletka.paletkastart(r.right / 2, r.bottom - r.bottom*0.1, 16, 100, 15, hwnd);
		pilka.pilkastart(r.right / 2, r.bottom - r.bottom*0.135, 10, 0, 0, hwnd);
		
		SetTimer(hwnd, 1, 16, NULL);
	}break;
	
	case WM_CHAR: {
		switch (wParam)
		{
		case ' ': {
			if (pilka.GetVelocityX() == 0 && pilka.GetVelocityY() == 0) //odpalenie pi³ki
			{
				pilka.SetVelocityX(0);
				pilka.SetVelocityY(-10);
				pilka.SetStart(TRUE);
			}
		}break;
		}
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
		
		paletka.rysujpaletke(hdcMem, hwnd);
		pilka.rysujpilke(hdcMem, hwnd);
		
		BitBlt(ps.hdc, r.left, r.top, r.right, r.bottom, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, hbmOld);
		DeleteObject(hbmMem);
		DeleteDC(hdcMem);
		EndPaint(hwnd, &ps);

	}break;
	
	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			if (GetAsyncKeyState(VK_LEFT)) //poruszanie siê paletk¹
			{
				if (paletka.GetX() - paletka.GetWidth() / 2 - paletka.GetVelocity() > r.left)
				{
					paletka.SetX(-paletka.GetVelocity());
					if (pilka.GetStart() == FALSE)
					{
						pilka.SetX(-paletka.GetVelocity());
					}
				}

			}
			if (GetAsyncKeyState(VK_RIGHT)) //poruszanie siê paletk¹
			{
				if (paletka.GetX() + paletka.GetWidth() / 2 + paletka.GetVelocity() < r.right)
				{
					paletka.SetX(paletka.GetVelocity());
					if (pilka.GetStart() == FALSE)
					{
						pilka.SetX(paletka.GetVelocity());
					}
				}
			}


			if (pilka.GetStart()) //poruszanie siê pi³ki
			{
				pilka.SetY(pilka.GetVelocityY());
				pilka.SetX(pilka.GetVelocityX());
			}

			if (zderzeniesciana(pilka, r) == 1)
			{
				KillTimer(hwnd, 1);
				if (MessageBox(hwnd, "PORA¯KA", "Game over", MB_OK) == IDOK)
				{
					DestroyWindow(hwnd);
				}
			}

			zderzeniepaletka(paletka, pilka, r);

			for (it = klocek.begin();it != klocek.end();) //tutaj mo¿e byæ b³¹d, który powoduje nieodbijanie siê pi³ki od klocków
			{
				zderzenieklocek(it, pilka);
				if (it->GetHit())
				{
					it = klocek.erase(it);
				}
				else ++it;
			}

			if (klocek.empty())
			{
				KillTimer(hwnd, 1);
				if (MessageBox(hwnd, "WYGRANA", "Koniec gry", MB_OK) == IDOK)
				{
					DestroyWindow(hwnd);
				}
			}
			InvalidateRect(hwnd, NULL, FALSE);
		}
		}
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
		wndclass.hIcon = LoadIcon(NULL,MAKEINTRESOURCE(IDB_BITMAP3));
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(255, 255, 255)));
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = "Arkanoid";


		if (RegisterClass(&wndclass) == 0)
			return FALSE;

		hwnd = CreateWindowEx(WS_EX_WINDOWEDGE, "Arkanoid", "Arkanoid", WS_OVERLAPPEDWINDOW^WS_THICKFRAME^WS_MAXIMIZEBOX| WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);

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