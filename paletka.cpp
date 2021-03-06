#include "paletka.h"
#include <windows.h>
#include "resource.h"

Paletka::Paletka()
{
	this->coordinates.x = 0;
	this->coordinates.y = 0;
	this->height = 0;
	this->width = 0;
	this->velocity = 0;
}
Paletka::~Paletka() {};
void Paletka::paletkastart(float x, float y, int height, int width, int velocity, HWND hwnd)
{
	this->coordinates.x = x;
	this->coordinates.y = y;
	this->height = height;
	this->width = width;
	this->velocity = velocity;

}
int Paletka::GetHeight()const
{
	return this->height;
}
int Paletka::GetWidth()const
{
	return this->width;
}
float Paletka::GetX()const
{
	return this->coordinates.x;
}
float Paletka::GetY()const
{
	return this->coordinates.y;
}
int Paletka::GetVelocity()const
{
	return this->velocity;
}
void Paletka::SetHeight(int size)
{
	this->height = size;
}
void Paletka::SetWidth(int size)
{
	this->width = size;
}
void Paletka::SetX(int x)
{
	this->coordinates.x += x;
}
void Paletka::SetY(int y)
{
	this->coordinates.y = y;
}
void Paletka::SetVelocity(int velocity)
{
	this->velocity = velocity;
}
BOOLEAN Paletka::NaPaletceX(float x, int size, int velocity)
{
	if (x + size + velocity >= coordinates.x - this->width / 2 && x - size + velocity <= coordinates.x + this->width / 2) return TRUE;
	return FALSE;
}
BOOLEAN Paletka::NaPaletceY(float y, int size, int velocity)
{
	if (y + size + velocity >= coordinates.y - this->height / 2 && y + size + velocity <= coordinates.y + this->height / 2) return TRUE;
	return FALSE;
}
void Paletka::Reset(RECT r)
{
	coordinates.x = r.right / 2;
	coordinates.y = r.bottom - r.bottom*0.1;
	velocity = 10;
}
void Paletka::rysujpaletke(HDC hdcMem, HWND hwnd)
{
	paletkaBm = LoadBitmap((HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDB_BITMAP3));
	HDC hLocalDC;
	hLocalDC = CreateCompatibleDC(hdcMem);
	HBITMAP hOldBmp = (HBITMAP)SelectObject(hLocalDC, paletkaBm);
	BitBlt(hdcMem, GetX() - GetWidth() / 2, GetY() - GetHeight() / 2, GetWidth(), GetHeight(), hLocalDC, 0, 0, SRCCOPY);
	SelectObject(hLocalDC, hOldBmp);
	DeleteDC(hLocalDC);
	DeleteObject(paletkaBm);
}