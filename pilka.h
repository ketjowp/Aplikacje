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
