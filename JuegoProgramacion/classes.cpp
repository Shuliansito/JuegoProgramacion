#include "classes.h"



void dibujarJugador(int x, int y, std::string simbolo, const std::string color)
{
    if (player1.nivel == 4) {
        gotoxy(25 + x, 3 + y);
        std::cout << color << BG_LVERDE << BOLD << simbolo << BG_NO << RESET;
    }else{
        gotoxy(25 + x, 3 + y);
        std::cout << color << BG << BOLD << simbolo << BG_NO << RESET;
    }
    
}

player player1(1,6,"O",4,NARANJA,true, 2);// X Y SIMBOLO NIVEL COLOR DISPARAR GUARDIAS

void player::recibirDano(int dm)
{
    player1.vida -= dm;
    if (player1.vida < 0)
    {
        player1.vida = 0;
    }
}