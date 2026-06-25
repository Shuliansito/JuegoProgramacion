
#include "classes.h"


void player::getDamaged(int dm)
{
    this->vida -= dm;
    if (this->vida < 0)
    {
        this->vida = 0;
    }
}