#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"

class player
{
public:
    int X;
    int Y;
    string simbolo;
    int nivel;
    string color;
    int vida;

    player(int x, int y, string s, int n, string c)
    {
        X = x;
        Y = y;
        simbolo = s;
        nivel = n;
        color = c;
        vida = 100;
    }
};

void dibujarJugador(int x, int y, std::string simbolo, const string color)
{
	gotoxy(25 + x, 3+y);
	cout << color << BG << BOLD << simbolo;
}


class enemy {//Para despues jeje
public:
	int X;
	int Y;
	int Vida;
	int damage;

};

player player1(1,1,"O", nivelglobal, NEGRO);


