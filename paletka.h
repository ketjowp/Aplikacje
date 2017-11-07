#include <windows.h>

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