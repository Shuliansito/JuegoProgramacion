
#include "classes.h"


void dibujarJugador(int x, int y, std::string simbolo, const string color)
{
    gotoxy(25 + x, 3 + y);
    cout << color << BG << BOLD << simbolo;
}

player player1(1, 6, "O", nivelglobal, NEGRO);

void player::getDamaged(int dm)
{
    this->vida -= dm;
    if (this->vida < 0)
    {
        this->vida = 0;
    }
}