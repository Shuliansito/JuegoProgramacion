#include "debug.h"

int debugKey=1;
void updateDebug() {
	
	if (debugKey % 2 == 0) {
		for (int i = 0; i < 30; i++) {
			gotoxy(0, i);
			std::cout << "                    " << RESET;
		}
		gotoxy(0, 7);
		std::cout << GRIS << "-Global-"<< RESET;
		gotoxy(0, 8);
		std::cout << GRIS << "Tick: " << NARANJA << tick << RESET;
		gotoxy(0, 14);
		std::cout << BLANCO << "-Guardias- "<< RESET;
		gotoxy(0, 15);
		std::cout << GRIS << "Guardias Lvl_2: " << AZUL << guardiasNivel2 << RESET;

		gotoxy(0, 19);
		std::cout << BLANCO << "-Player Info- "<<RESET;
		gotoxy(0, 20);
		std::cout << GRIS << "Player_X: " << ROJO << player1.X << RESET;
		gotoxy(0, 21);
		std::cout << GRIS << "Player_Y: " << ROJO << player1.Y << RESET;
		gotoxy(0, 22);
		std::cout << GRIS << "Health: " << ROJO << player1.vida << RESET;
		gotoxy(0, 23);
		std::cout << GRIS << "Nivel: " << NARANJA << player1.nivel << RESET;
		
		gotoxy(0, 24);
		std::cout << GRIS << "Can_Shoot: " << NARANJA << player1.canShootWeapong << RESET;
		gotoxy(0, 25);
		std::cout << GRIS << "Shoot_Delay: " << GRIS << shootDelay << RESET;
		
		
	
	
	}
	else {
		for (int i=0; i < 30; i++) {
			gotoxy(0, i);
			std::cout << "                    " << RESET;
		}
		
		
	}
}

