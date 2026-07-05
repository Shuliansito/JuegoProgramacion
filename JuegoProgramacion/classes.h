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

    player(int x, int y, std::string s, int n, std::string c)
    {
        X = x;
        Y = y;
        simbolo = s;
        nivel = n;
        color = c;
        vida = 100;
    }
    void recibirDano(int dm);
};

void dibujarJugador(int x, int y, std::string simbolo, const std::string color);


class enemy {//Para despues jeje
public:
	int X;
	int Y;
	int Vida;
	int damage;

};


extern player player1;

