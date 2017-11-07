#include <windows.h>

class Klocek
{
public:
	Klocek(int x, int y, int sizeX, int sizeY, BOOLEAN hit);
	~Klocek();
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
	HBITMAP klocekBm;
	BOOLEAN hitted;
	POINT coordinates;
	int sizeX;
	int sizeY;
};

