#include "klocek.h"
#include "pilka.h"
#include "paletka.h"
#include <windows.h>
#include <list>

int zderzeniesciana(Pilka &pilka, RECT r);
void zderzeniepaletka(Paletka &paletka, Pilka &pilka, RECT r);
void zderzenieklocek(std::list<Klocek>::iterator &klocek, Pilka pilka);
