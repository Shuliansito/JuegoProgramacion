#include "classes.h"



void dibujarJugador(int x, int y, std::string simbolo, const std::string color)
{
    if (player1.nivel == 4||player1.nivel==6) {
        gotoxy(25 + x, 3 + y);
        std::cout << color << BG_LVERDE << BOLD << simbolo << BG_NO << RESET;

    }
    else if (player1.nivel == 5) {
        gotoxy(25 + x, 3 + y);
        std::cout << color << BG_GRIS << BOLD << simbolo << BG_NO << RESET;
    }
    else{
        gotoxy(25 + x, 3 + y);
        std::cout << color << BG << BOLD << simbolo << BG_NO << RESET;
    }
    
}

player player1(1,6,"O",1,NARANJA,true, 0);// X Y SIMBOLO NIVEL COLOR DISPARAR GUARDIAS

void player::recibirDano(int dm)
{
    player1.vida -= dm;
    if (player1.vida < 0)
    {
        player1.vida = 0;
    }
    LOG("Player damaged");
}