#pragma once
#include "Shuli.h"



class Guardia{
public:
	int x, y;
	int nivelGuardia;
	bool vivo;
};


const int GUARDIAS_MAX = 15;
extern Guardia guardia[GUARDIAS_MAX];
extern int cantGuardias;


void Guardia_Ini(int x, int y, int nivel);

bool esPisable(char c);

void Guardia_Mover(Guardia& g, std::string mapa[]);

void Guardia_Update(std::string nivel1[], std::string nivel2[], std::string nivel3[], int tickActual);
