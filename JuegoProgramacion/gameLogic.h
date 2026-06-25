#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "debugMode.h"
#include "mapLogic.h"
#include "classes.h"

using namespace std;

bool playing = true;
int debugMode = 1;
int nivelglobal = 1;
int prevX1;
int prevY1;

char tile=' ';



int collision(int x, int y, string mapa[])
{
    //Caso 0: No hay colision de ningun tipo
    if (mapa[y][x] == ' ') { return 0;}
    //Caso 1: Colision pared
    else if(mapa[y][x] == '%'){ return 1; }
    //Caso 2: Colision Salida
    else if (mapa[y][x] == 'E') { return 2; }
    //Caso 3: Colision Enemigo
    else if (mapa[y][x] == 'X') { return 3; }

    return 0;
}

void levelCollision() {
    
    if (nivelglobal == 1) {
        if (collision(player1.X, player1.Y, level1) == 1)
        {
            player1.X = prevX1;
            player1.Y = prevY1;
        }
        else if (collision(player1.X, player1.Y, level1) == 2) {
            player1.nivel++;
            nivelglobal++;
            if (chooseMap() == 2) dibujarMapa(level2, 20);
            player1.X = 1;
            player1.Y = 1;
        }
    }
    if (nivelglobal ==2) {
        if (collision(player1.X, player1.Y, level2) == 1)
        {
            player1.X = prevX1;
            player1.Y = prevY1;
        }
        else if (collision(player1.X, player1.Y, level2) == 2) {
            player1.nivel--;
            nivelglobal--;
            if (chooseMap() == 1) dibujarMapa(level1, 20);
            player1.X = 1;
            player1.Y = 1;
        }
        
    }
}
void inputMovement()
{
    char tile;

    switch (player1.nivel)
    {
    case 1:
        tile = level1[player1.Y][player1.X];
        break;

    case 2:
        tile = level2[player1.Y][player1.X];
        break;
    }

    if (_kbhit())
    {
        gotoxy(20 + player1.X, player1.Y);
        cout << " ";

        

        debug(player1.X, player1.Y);

        char tecla = _getch();

        prevX1 = player1.X;
        prevY1 = player1.Y;

     

        if (tecla == 'm') debugMode++;

        if (tecla == 'd') player1.X++;
        else if (tecla == 'a') player1.X--;
        else if (tecla == 'w') player1.Y--;
        else if (tecla == 's') player1.Y++;

   
        levelCollision();
        

   

       
    }
}

void dibujarJugador(int x, int y, std::string simbolo, const string color)
{
    gotoxy(20 + x, y);
    cout << color << BOLD << simbolo;
}

void playerHelp()
{
    gotoxy(24, 20);
    cout << ROJO << "Player 1:     ";
    gotoxy(24, 21);
    cout << ROJO << "   W          ";
    gotoxy(24, 22);
    cout << ROJO << " A S D        ";
    gotoxy(24, 23);
    cout << ROJO << "To  Move      ";

   
}


