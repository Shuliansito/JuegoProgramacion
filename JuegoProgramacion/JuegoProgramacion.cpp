#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include "Shuli.h"
#include "gameLogic.h"
#include "debugMode.h"
#include "classes.h"
int main()
{
    
    SetConsoleOutputCP(CP_UTF8);
    showCursor(false);
    
        if (nivelglobal == 1) dibujarMapa(level1, 20);
        if (nivelglobal == 2) dibujarMapa(level2, 20);
    
    
    player1.X = 1;
    player1.Y = 1;
    player1.simbolo = "@";
    player1.nivel = 1;
    player1.color = "ROJO";

    while (playing)
    {
        

        inputMovement();

        playerHelp();

        dibujarJugador(player1.X, player1.Y, player1.simbolo, ROJO);
        

    }

    gotoxy(30, 10);
    std::cout << BOLD << NARANJA << "Los jugadores colisionaron! Fin del juego.";

    Sleep(1500);
    _getch();
    return 67;
}