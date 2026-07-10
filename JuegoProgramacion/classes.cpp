#include "classes.h"


void dibujarJugador(int x, int y, std::string simbolo, const std::string color)
{
    gotoxy(25 + x, 3 + y);
    std::cout << color << BG << BOLD << simbolo<<BG_NO<<RESET;
}

player player1(1, 6, "O", 1, NARANJA, false, 0);

void player::recibirDano(int dm)
{
    player1.vida -= dm;
    if (player1.vida < 0)
    {
        player1.vida = 0;
    }
}