#include "classes.h"


void dibujarJugador(int x, int y, std::string simbolo, const std::string color)
{
    gotoxy(25 + x, 3 + y);
    std::cout << color << BG << BOLD << simbolo<<BG_NO<<RESET;
}

player player1(1, 6, "O", nivelglobal, NARANJA);

void player::getDamaged(int dm)
{
    this->vida -= dm;
    if (this->vida < 0)
    {
        this->vida = 0;
    }
}