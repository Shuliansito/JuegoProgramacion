#include "Patrullas.h"
#include "gameLogic.h"
#include "classes.h"


Guardia guardia[GUARDIAS_MAX];
int cantGuardias = 0;

void Guardia_Ini(int x, int y, int x1, int y1, int x2, int y2, int nivel) {
	Guardia g = guardia[cantGuardias];
	g.x = x;
	g.y = y;
	g.x1 = x1;
	g.y1 = y1;
	g.x2 = x2;
	g.y2 = y2;
	g.nivelGuardia = nivel;
	g.dx = (x2 > x1) ? 1 : 0;
	g.dy = (y2 > y1) ? 1 : 0;
	cantGuardias++;
}


void Guardia_Update(string nivel[][20]) {


}