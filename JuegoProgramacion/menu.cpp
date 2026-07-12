#include <iostream>
#include <conio.h>
#include "mapLogic.h"
#include "Shuli.h"

bool inMenu = true;

 int opcion = 0;

using namespace std;
void menuLogic() {
	//Logica de las opciones
	if (_kbhit()) {

		char tecla = _getch();
		if (tecla == 'w')	   opcion--;
		else if (tecla == 's') opcion++;

		if (opcion > 2)opcion = 0;
		if (opcion < 0)opcion = 2;

		if (tecla == '\r') {
			if (opcion == 0)inMenu = false;
			if (opcion == 1)inMenu = false;
			if (opcion == 2)exit(0);
		}
	}

	//Si opcion es igual a i, dibujar un >, sino un ' '
	for (int i = 0; i < 3; i++) {
		gotoxy(49, 10 + i);
		if (opcion == i) cout << GRIS << ">"<<RESET;
		else cout << " " << RESET;
	}
}