#include <windows.h>
#include "zderzenia.h"
#include <list>


int zderzeniesciana(Pilka &pilka, RECT r)
{
	if (pilka.GetY() + pilka.GetSize() >= r.bottom)
	{
		return 1;
	}
	else if (pilka.GetY() - pilka.GetSize() + pilka.GetVelocityY() <= r.top)
	{
		pilka.SetVelocityY(-pilka.GetVelocityY());
	}
	else if (pilka.GetX() + pilka.GetSize() + pilka.GetVelocityX() >= r.right)
	{
		pilka.SetVelocityX(-pilka.GetVelocityX());
	}
	else if (pilka.GetX() - pilka.GetSize() + pilka.GetVelocityX() <= r.left)
	{
		pilka.SetVelocityX(-pilka.GetVelocityX());
	}
	return 0;
}

void zderzeniepaletka(Paletka &paletka, Pilka &pilka, RECT r)
{
	if (paletka.NaPaletceY(pilka.GetY(), pilka.GetSize(), pilka.GetVelocityY()) && paletka.NaPaletceX(pilka.GetX(), pilka.GetSize(), pilka.GetVelocityX()))
	{
		float pozpilki = pilka.GetX() - paletka.GetX();
		float kat = (pozpilki / (paletka.GetWidth() / pilka.GetSize()));
		pilka.SetVelocityX(kat);
		pilka.SetVelocityY(-pilka.GetVelocityY());
	}
}

void zderzenieklocek(std::list<Klocek>::iterator &klocek, Pilka pilka) //nie odbija siê
{
	if ((pilka.GetX() + pilka.GetVelocityX() + pilka.GetSize() >= klocek->GetX() - klocek->GetSizeX() && pilka.GetX() - pilka.GetSize() + pilka.GetVelocityX() <= klocek->GetX() + klocek->GetSizeX())
		&& (pilka.GetY() + pilka.GetVelocityY() + pilka.GetSize() >= klocek->GetY() - klocek->GetSizeY() && pilka.GetY() - pilka.GetSize() + pilka.GetVelocityY() <= klocek->GetY() + klocek->GetSizeY()))
	{
		if (pilka.GetX() + pilka.GetSize() < klocek->GetX() - klocek->GetSizeX() && pilka.GetX() + pilka.GetVelocityX() + pilka.GetSize() >= klocek->GetX() - klocek->GetSizeX())
		{
			pilka.SetVelocityX(-pilka.GetVelocityX());
			klocek->SetHit(TRUE);
		}

		if (pilka.GetX() - pilka.GetSize() > klocek->GetX() + klocek->GetSizeX() && pilka.GetX() + pilka.GetVelocityX() - pilka.GetSize() <= klocek->GetX() + klocek->GetSizeX())
		{
			pilka.SetVelocityX(-pilka.GetVelocityX());
			klocek->SetHit(TRUE);
		}

		if (pilka.GetY() + pilka.GetSize() < klocek->GetY() - klocek->GetSizeY() && pilka.GetY() + pilka.GetVelocityY() + pilka.GetSize() >= klocek->GetY() - klocek->GetSizeY())
		{
			pilka.SetVelocityY(-pilka.GetVelocityY());
			klocek->SetHit(TRUE);
		}

		if (pilka.GetY() - pilka.GetSize() > klocek->GetY() + klocek->GetSizeY() && pilka.GetY() + pilka.GetVelocityY() - pilka.GetSize() <= klocek->GetY() + klocek->GetSizeY())
		{
			pilka.SetVelocityY(-pilka.GetVelocityY());
			klocek->SetHit(TRUE);
		}
	}
}

