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
    
    dibujarMapa(level0, 20);

    _getch();

    dibujarMapa(level1, 20);
        
    
    
    

    while (playing)
    {
        

        inputMovement();

        dibujarJugador(player1.X, player1.Y, player1.simbolo, player1.color);
        

    }

   

    Sleep(1500);
   
    return 67;
}