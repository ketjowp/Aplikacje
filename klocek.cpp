#include "klocek.h"
#include "resource.h"
#include <Windows.h>

Klocek::Klocek(int x, int y, int sizeX, int sizeY,BOOLEAN hit)
{
	this->coordinates.x = x;
	this->coordinates.y = y;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->hitted = hit;
	
}
Klocek::~Klocek()
{
}

int Klocek::GetSizeX()const
{
	return this->sizeX;
}
int Klocek::GetSizeY()const
{
	return this->sizeY;
}
int Klocek::GetX()const
{
	return this->coordinates.x;
}
int Klocek::GetY()const
{
	return this->coordinates.y;
}
void Klocek::SetSizeX(int size)
{
	this->sizeX = sizeX;
}
void Klocek::SetSizeY(int size)
{
	this->sizeY = sizeY;
}
void Klocek::SetX(int x)
{
	this->coordinates.x += x;
}
void Klocek::SetY(int y)
{
	this->coordinates.y += y;
}
void Klocek::SetHit(BOOLEAN hit)
{
	this->hitted = hit;
}
BOOLEAN Klocek::GetHit()const
{
	return hitted;
}

void Klocek::Rysujklocka(HDC hWinDC, HWND hwnd)
{
	klocekBm = LoadBitmap((HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDB_BITMAP1));
	HDC hLocalDC;
	hLocalDC = CreateCompatibleDC(hWinDC);
	BITMAP qBitmap;
	GetObject(reinterpret_cast<HGDIOBJ>(klocekBm), sizeof(BITMAP),reinterpret_cast<LPVOID>(&qBitmap));
	HBITMAP hOldBmp = (HBITMAP)SelectObject(hLocalDC, klocekBm);
	BitBlt(hWinDC, GetX() - GetSizeX(), GetY() - GetSizeY(), GetX() + GetSizeX(), GetY() + GetSizeY(), hLocalDC, 0, 0, SRCCOPY);
	SelectObject(hLocalDC, hOldBmp);
	DeleteDC(hLocalDC);
	DeleteObject(klocekBm);
}
