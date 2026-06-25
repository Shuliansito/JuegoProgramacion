
#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "debugMode.h"

using namespace std;

extern int nivelglobal;

string level1[20] = {
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                            ",
    "%  %         %%%%%%%%%%%%          %%                            ",
    "%            %%%%%%%%%%%%          %%                            ",
    "%%%%                   %%          %%                            ",
    "%                      %%          %%          Nivel 1           ",
    "%                %%                %%                            ",
    "%                %%                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
    "%           %%   %%    %%                                       %",
    "%           %%%%%%%%%%%%%                                       %",
    "%           %%         %%                                       %",
    "%                                                               %",
    "%                                                               %",
    "%                                                               %",
    "%                                 E                             %",
    "%                                                               %",
    "%                                                               %",
    "%%%%%%%%%                                                    %%%%",
    "%%%%%%%%%                                                       %",
    "%%%%%%%%%                                                    %  %",
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
};
string level2[20] = {
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                            ",
    "%  %                               %%                            ",
    "%                                  %%                            ",
    "%%%%                               %%                            ",
    "%                                  %%          Nivel 2           ",
    "%                                  %%                            ",
    "%                                  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
    "%                                                               %",
    "%                                                               %",
    "%                        E                                      %",
    "%                                                               %",
    "%                                                               %",
    "%                                                               %",
    "%                                                               %",
    "%                                                               %",
    "%                                                               %",
    "%%%%%%%%%                                                    %%%%",
    "%%%%%%%%%                                                       %",
    "%%%%%%%%%                                                    %  %",
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
};

void dibujarMapa(string mapa[], int filas)
{
    system("cls");
    for (int y = 0; y < filas; y++)
    {
        gotoxy(20, y);

        for (int x = 0; x < mapa[y].size(); x++)
        {
            switch (mapa[y][x])
            {
            case 'A': std::cout << GRIS << "╔"; break;
            case 'B': std::cout << GRIS << "╗"; break;
            case 'C': std::cout << GRIS << "╚"; break;
            case 'D': std::cout << GRIS << "╝"; break;
            case '=': std::cout << GRIS << "═"; break;
            case '|': std::cout << GRIS << "║"; break;
            case '%': std::cout << GRIS << "█"; break;
            default:  std::cout << mapa[y][x];
            }
        }
    }
}

int chooseMap() {
    if (nivelglobal == 1) return 1;
    if (nivelglobal == 2) return 2;
}


