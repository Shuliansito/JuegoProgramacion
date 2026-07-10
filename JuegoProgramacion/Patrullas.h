#pragma once
#include "Shuli.h"

const int GUARDIAS_MAX = 10;
extern Guardia guardia[GUARDIAS_MAX];
extern int cantGuardias;

class Guardia{
public:
	int x, y;
	int nivelGuardia;
};

void Guardia_Ini(int x, int y, int nivel);

void Guardia_Update(string niveles[][20]);