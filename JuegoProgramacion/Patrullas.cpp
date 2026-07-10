#include "Patrullas.h"
#include "gameLogic.h"
#include "classes.h"


Guardia guardia[GUARDIAS_MAX];
int cantGuardias = 0;

void Guardia_Ini(int x, int y, int nivel) {
	Guardia g = guardia[cantGuardias];
	g.x = x;
	g.y = y;
	g.nivelGuardia = nivel;

	cantGuardias++;
}


void Guardia_Update(string nivel[][20]) {


}