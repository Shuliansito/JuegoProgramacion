#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"

extern int nivelglobal;

class player
{
public:
    int X;
    int Y;
    std::string simbolo;
    int nivel;
    std::string color;
    int vida;
    bool canShootWeapong;

    player(int x, int y, std::string s, int n, std::string c, bool canUWeapon)
    {
        X = x;
        Y = y;
        simbolo = s;
        nivel = n;
        color = c;
        canShootWeapong = canUWeapon;
        vida = 100;

    }

    void recibirDano(int dm);
};

void dibujarJugador(int x, int y, std::string simbolo, const std::string color);





extern player player1;

