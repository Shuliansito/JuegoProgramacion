#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "debug.h"
#include "mapLogic.h"
#include "classes.h"

using namespace std;

extern player player1;
bool playing = true;

int nivelglobal = 1;
int prevX1;
int prevY1;
int nivelActual;

char tile;



string* niveles[3] = { level1, level2, level3 };

int collision(int x, int y, string mapa[])
{
    if (mapa[y][x] == ' ') { return 0; }
    else if (mapa[y][x] == '%'|| mapa[y][x] == '|'||mapa[y][x] == '-') { return 1; }
    else if (mapa[y][x] == 'E') { return 2; }
    else if (mapa[y][x] == 'P') { return 3; }
    else if (mapa[y][x] == 'D') { return 4; }


    return 0;
}

void actionCollision() {
    int nivelActual = nivelglobal - 1;
    
    int col = collision(player1.X, player1.Y, niveles[nivelActual]);

    if (col == 1)
    {
        player1.X = prevX1;
        player1.Y = prevY1;
    }
    else if (col == 2)
    {
        nivelglobal++;

        if (nivelglobal > 3)
            nivelglobal = 1;

        player1.nivel = nivelglobal;

        dibujarMapa(niveles[nivelglobal - 1], 20);

        if (nivelglobal == 1) {
            player1.X = 1;
            player1.Y = 6;
        }else if (nivelglobal == 2){
            player1.X = 1;
            player1.Y = 1;
        }
        else if (nivelglobal == 3) {
            player1.X = 1;
            player1.Y = 12;
        }
    }else if (col == 4) {
        nivelglobal--;

        if (nivelglobal > 3)
            nivelglobal = 1;
        if (nivelglobal < 0)
            nivelglobal = 1;

        player1.nivel = nivelglobal;

        dibujarMapa(niveles[nivelglobal - 1], 20);

        if (nivelglobal == 1) {
            player1.X = 63;
            player1.Y = 18;
        }else if (nivelglobal == 2) {
            player1.X = 63;
            player1.Y = 12;
        }else if (nivelglobal == 3) {
            player1.X = 45;
            player1.Y = 12;
        }
        
        
    }
    else if (col == 3) { playing = false; }
}

void inputMovement()
{
    
    switch (player1.nivel)
    {
    case 1:
        tile = level1[player1.Y][player1.X];
        break;

    case 2:
        tile = level2[player1.Y][player1.X];
        break;

    case 3:
        tile = level3[player1.Y][player1.X];
        break;
    }

    if (_kbhit())
    {
        
        gotoxy(25 + player1.X, 3 + player1.Y);
        cout <<BG<< " ";

        

        char tecla = _getch();

        prevX1 = player1.X;
        prevY1 = player1.Y;

        if (tecla == 'm') debugKey++;

        if (tecla == 'd') player1.X++;
        else if (tecla == 'a') player1.X--;
        else if (tecla == 'w') player1.Y--;
        else if (tecla == 's') player1.Y++;

        actionCollision();
    }
}