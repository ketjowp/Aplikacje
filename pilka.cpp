#include "pilka.h"
#include <windows.h>
#include "resource.h"
#include <list>
#include "klocek.h"

Pilka::Pilka()
{
	this->coordinates.x = 0;
	this->coordinates.y = 0;
	this->size = 0;
	this->velocityX = 0;
	this->velocityY = 0;
	this->start = FALSE;
}
Pilka::~Pilka() {};
void Pilka::pilkastart(int x, int y, int size, int velocityX, int velocityY, HWND hwnd)
{
	this->coordinates.x = x;
	this->coordinates.y = y;
	this->size = size;
	this->velocityY = velocityY;
	this->velocityX = velocityX;

}
int Pilka::GetSize()const
{
	return this->size;
}
int Pilka::GetX()const
{
	return this->coordinates.x;
}
int Pilka::GetY()const
{
	return this->coordinates.y;
}
int Pilka::GetVelocityX()const
{
	return this->velocityX;
}
int Pilka::GetVelocityY()const
{
	return this->velocityY;
}
void Pilka::SetSize(int size)
{
	this->size = size;
}
void Pilka::SetX(int x)
{
	this->coordinates.x += x;
}
void Pilka::SetY(int y)
{
	this->coordinates.y += y;
}
void Pilka::SetVelocityX(int velocity)
{
	this->velocityX = velocity;
}
bool Pilka::SetVelocityY(int velocity)
{
	this->velocityY = velocity;
	return TRUE;
}
void Pilka::Reset(RECT r)
{
	coordinates.x = r.right / 2;
	coordinates.y = r.bottom - r.bottom*0.135;
	velocityX = 0;
	velocityY = 0;
	start = FALSE;
}


BOOLEAN Pilka::GetStart()const
{
	return start;
}
void Pilka::SetStart(BOOLEAN s)
{
	start = s;
}
void Pilka::rysujpilke(HDC hdcMem, HWND hwnd)
{
	pilkaBm = LoadBitmap((HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDB_BITMAP2));
	HDC hLocalDC;
	hLocalDC = CreateCompatibleDC(hdcMem);
	BITMAP qBitmap;
	GetObject(reinterpret_cast<HGDIOBJ>(pilkaBm), sizeof(BITMAP),
		reinterpret_cast<LPVOID>(&qBitmap));
	HBITMAP hOldBmp = (HBITMAP)SelectObject(hLocalDC, pilkaBm);
	BitBlt(hdcMem, GetX() - GetSize(), GetY() - GetSize(), GetX() + GetSize(), GetY() + GetSize(), hLocalDC, 0, 0, SRCCOPY);
	SelectObject(hLocalDC, hOldBmp);
	DeleteDC(hLocalDC);
	DeleteObject(pilkaBm);
}