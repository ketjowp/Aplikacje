
#include <Windows.h>

class Paletka
{
public:
	Paletka();
	~Paletka();
	void paletkastart(float x, float y, int height, int width, int velocity, HWND hwnd);
	float GetX()const;
	float GetY()const;
	int GetWidth()const;
	int GetHeight()const;
	int GetVelocity()const;
	void SetX(int x);
	void SetY(int y);
	void SetWidth(int size);
	void SetHeight(int size);
	void SetVelocity(int veloc);
	void rysujpaletke(HDC hdcMem, HWND hwnd);
	BOOLEAN NaPaletceX(float x, int size, int velocity);
	BOOLEAN NaPaletceY(float y, int size, int velocity);
	void Reset(RECT r);

private:
	POINT coordinates;
	int height;
	int width;
	int velocity;
};
Paletka::Paletka()
{
	this->coordinates.x = 0;
	this->coordinates.y = 0;
	this->height = 0;
	this->width = 0;
	this->velocity = 0;
}
Paletka::~Paletka() {};
void Paletka::paletkastart(float x, float y, int height,int width, int velocity,HWND hwnd)
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
BOOLEAN Paletka::NaPaletceX(float x,int size, int velocity)
{
	if (x + size + velocity >= coordinates.x - this->width/2 && x - size + velocity <= coordinates.x + this->width/2) return TRUE;
	return FALSE;
}
BOOLEAN Paletka::NaPaletceY(float y, int size, int velocity)
{
	if (y + size + velocity >= coordinates.y - this->height/2 && y + size + velocity <= coordinates.y +this->height/2) return TRUE;
	return FALSE;
}
void Paletka::Reset(RECT r)
{
	coordinates.x = r.right / 2;
	coordinates.y = r.bottom - r.bottom*0.1;
	velocity = 10;
}
void Paletka::rysujpaletke(HDC hdcMem,HWND hwnd)
{
}
