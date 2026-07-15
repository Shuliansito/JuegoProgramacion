#include <iostream>
#include <conio.h>
#include "mapLogic.h"
#include "Shuli.h"

bool inMenu = true;

 int opcion = 0;

using namespace std;

void addNameToCharacter() {
	cout << MOSTRAR;
	std::string n;
	gotoxy(50, 13);
	cout << "Ingrese su nombre: ";
	cin >> n;
	player1.setNombre(n);
	cout << ESCONDER;
	LOG_FILE("[NOMBRE] El jugador cambio su nombre a " + player1.getNombre());
	LOG("[NOMBRE] El jugador cambio su nombre a " + player1.getNombre());
}

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
			if (opcion == 1) {
				dibujarMapa(controles, 20);
				gotoxy(42, 16);
				cout << GRIS << "Pulse cualquier tecla para salir";
				_getch(); 
				dibujarMapa(level0, 20);
			}
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