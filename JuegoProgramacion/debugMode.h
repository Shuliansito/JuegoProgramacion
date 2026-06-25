#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "gameLogic.h"


extern int debugMode;
extern char tile;
int distancia = 10;
extern int nivelActual;
extern int nivelglobal;


void debug(int p1X, int p1Y) {


	gotoxy(0, 15+distancia);
	std::cout << BG_NO << "             ";
	gotoxy(0, 16+distancia);
	std::cout << BG_NO << "             ";
	gotoxy(0, 18+distancia);
	std::cout << BG_NO << "             ";
	gotoxy(0, 19+distancia);
	std::cout << BG_NO << "             ";
	gotoxy(0, 21+distancia);
	std::cout << BG_NO << "                        ";


	if (debugMode % 2 == 0) {
		gotoxy(0, 15+distancia);
		std::cout << ROJO << "P1 X: " << p1X+20;
		gotoxy(0, 16+distancia);
		std::cout << ROJO << "P1 Y: " << p1Y;
		gotoxy(0, 17 + distancia);
		std::cout << NARANJA << "Nivel Actual: " << nivelActual;
		gotoxy(0, 18 + distancia);
		std::cout << ROJO << "Nivel global: " << nivelglobal;
		

	
	}
	


	
	
}
