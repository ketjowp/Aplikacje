#include <Windows.h>

class Klocek
{
public:
	klocek(int x, int y, int sizeX, int sizeY, BOOLEAN hit);
	~klocek();
	int GetX()const;
	int GetY()const;
	int GetSizeY()const;
	int GetSizeX()const;
	void SetX(int x);
	void SetY(int y);
	void SetSizeX(int size);
	void SetSizeY(int size);
	void SetHit(BOOLEAN hit);
	void Rysujklocka(HDC hdcMem, HWND hwnd);
	BOOLEAN GetHit()const;
private:
	BOOLEAN hitted;
	POINT coordinates;
	int sizeX;
	int sizeY;
};


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
}