#include "debug.h"
int debugKey=0;
void updateDebug() {

	if (debugKey % 2 == 0) {
		gotoxy(0, 20);
		std::cout << "                          " << RESET;
		gotoxy(0, 21);
		std::cout << "                          " << RESET;
		gotoxy(0, 20);
		std::cout << GRIS << "Player X: " << ROJO << player1.X << RESET;
		gotoxy(0, 21);
		std::cout << GRIS << "Player Y: " << ROJO << player1.Y << RESET;
	}
	else {
		gotoxy(0, 20);
		std::cout << "                          " << RESET;
		gotoxy(0, 21);
		std::cout << "                          " << RESET;
	}
}

