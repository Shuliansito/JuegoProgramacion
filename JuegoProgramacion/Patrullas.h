#pragma once
#include "Shuli.h"

const int GUARDIAS_MAX = 10;
extern Guardia guardia[GUARDIAS_MAX];
extern int cantGuardias;

class Guardia{
public:
	int x, y, x1, y1, x2, y2, dx, dy;
	int nivelGuardia;
};

void Guardia_Ini(int x, int y, int x1,int y1, int x2, int y2, int nivel);

void Guardia_Update(string niveles[][20]);