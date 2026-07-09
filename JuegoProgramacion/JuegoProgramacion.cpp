#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Shuli.h"
#include "gameLogic.h"
#include "menu.h"
#include "disparos.h"
#include "classes.h"
#include "ticks.h"


extern int tick = 0;

int cops = 0;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("title Prison Escape");
    showCursor(false);
    
    dibujarMapa(level0, 20);
    while (inMenu) {
        gotoxy(60, 11);
        cout << NARANJA << "ENTER" << RESET;
        
        
        menuLogic();
        
    } 
    
   

    dibujarMapa(level1, 20);
    
    iniciarTicks(20);
    std::cout << RESET;
   
    while (playing)
    {
        std::cout << BG_NO;
        inputMovement();
       
        dibujarJugador(player1.X, player1.Y, player1.simbolo, player1.color);

        if (debeEjecutarTick())
        {
            actualizarBalas(niveles[nivelglobal - 1]);
            playerHelps();
            if (shootDelay > 0) { shootDelay--; }
            
            tick++;
        }

       
        updateDebug();
        esperarTick();
        if (shootDelay < 0) {shootDelay = 0;}
    }


    Sleep(1500);

    return 67;
}