#include <windows.h>
#include <list>

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
	void SetVelocityX(int velocity);
	bool SetVelocityY(int velocity);
	void Reset(RECT r);
	BOOLEAN GetStart()const;
	void SetStart(BOOLEAN start);
	void rysujpilke(HDC hdcMem, HWND hwnd);

private:
	HBITMAP pilkaBm;
	POINT coordinates;
	int size;
	float velocityX;
	float velocityY;
	BOOLEAN start;
};
