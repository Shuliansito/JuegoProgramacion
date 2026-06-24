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



bool esPared(int x, int y, string mapa[])
{
    return mapa[y][x] != ' ';
}

void inputMovement()
{
    if (_kbhit())
    {
        gotoxy(20 + player1.X, player1.Y);
        cout << " ";

        

        debug(player1.X, player1.Y);

        char tecla = _getch();

        int prevX1 = player1.X;
        int prevY1 = player1.Y;

     

        if (tecla == 'm') debugMode++;

        if (tecla == 'd') player1.X++;
        else if (tecla == 'a') player1.X--;
        else if (tecla == 'w') player1.Y--;
        else if (tecla == 's') player1.Y++;

   

        if (esPared(player1.X, player1.Y, level1))
        {
            player1.X = prevX1;
            player1.Y = prevY1;
        }

   

       
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