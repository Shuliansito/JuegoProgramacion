#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Shuli.h"
#include "gameLogic.h"
#include "menu.h"
#include "classes.h"
#include "ticks.h"


int tick = 0;

int cops = 0;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    system("title Prison Escape");
    showCursor(false);
    

    while (inMenu) {

        dibujarMapa(level0, 20);
		
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
            
            playerHelps();
            tick++;
        }

       
        updateDebug();
        esperarTick();
    }


    Sleep(1500);

    return 67;
}