
#include <windows.h>


class Pilka
{
public:
	Pilka();
	~Pilka();
	void pilkastart(int x, int y, int size, int velocityX, int velocityY, HWND hwnd);
	int GetX()const;
	int GetY()const;
	int GetSize()const;
	int GetVelocityX()const;
	int GetVelocityY()const;
	void SetX(int x);
	void SetY(int y);
	void SetSize(int size);
	void SetVelocityX(int veloc);
	void SetVelocityY(int veloc);
	void Reset(RECT r);
	BOOLEAN GetStart()const;
	void SetStart(BOOLEAN start);
	void rysujpilke(HDC hdcMem, HWND hwnd);

private:
	POINT coordinates;
	int size;
	float velocityX;
	float velocityY;
	BOOLEAN start;
};

Pilka::Pilka()
{
	this->coordinates.x = 0;
	this->coordinates.y = 0;
	this->size = 0;
	this->velocityX = 0;
	this->velocityY = 0;
	this->start = TRUE;
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
void Pilka::SetVelocityY(int velocity)
{
	this->velocityY = velocity;
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
}