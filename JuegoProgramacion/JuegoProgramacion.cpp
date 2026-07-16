/////////////////////////////////////////////////////////////
//   ██████╗ ██████╗ ██╗   ██╗███████╗██╗███╗   ██╗███████╗//
//  ██╔════╝ ██╔══██╗╚██╗ ██╔╝██╔════╝██║████╗  ██║██╔════╝//
//  ██║      ██████╔╝ ╚████╔╝ █████╗  ██║██╔██╗ ██║█████╗  //
//  ██║      ██╔══██╗  ╚██╔╝  ██╔══╝  ██║██║╚██╗██║██╔══╝  //
//  ╚██████╗ ██║  ██║   ██║   ██║     ██║██║ ╚████║███████╗//
//   ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝╚═╝  ╚═══╝╚══════╝//
/////////////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

#include "Shuli.h"
#include "gameLogic.h"
#include "Patrullas.h"
#include "menu.h"
#include "disparos.h"
#include "classes.h"
#include "ticks.h"
#include "Cloaca.h"




extern int tick = 0;
int cops = 0;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    system("title Prison Escape");
    showCursor(false);
    
    addNameToCharacter();
    
    dibujarMapa(level0, 20);


    while (inMenu) {
        menuLogic();
        
    } 
    


    dibujarMapa(niveles[player1.nivel-1], 20);
    
    
    iniciarTicks(20);
    std::cout << RESET;
    cargarGuardias();

    while (playing&&player1.vida>=1)
    {
        std::cout << BG_NO;
        
        
        if (player1.nivel == 6 && player1.X >= 47) {

            playing = false;
            player1.gano = true;
            
        }
        inputMovement();
       
        dibujarJugador(player1.X, player1.Y, player1.simbolo, player1.color);

        if (debeEjecutarTick())
        {
            cloacaLogic();
            Guardia_Update(level1, level2, level4, tick);
            actualizarBalas(niveles[player1.nivel - 1]);
            playerHelps();
            if (shootDelay > 0) { shootDelay--; }
            
            tick++;
        }

       
        updateDebug();
        esperarTick();
        
        if (shootDelay < 0) {shootDelay = 0;}
    }
    if (player1.gano) {

        dibujarSubNivel(carta, 20);
    }
    


    Sleep(1500);

    return 67;
}