
#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "debugMode.h"

using namespace std;


string level1[20] = {
    "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                            ",
    "%  %         %%%%%%%%%%%%          %%                            ",
    "%            %%%%%%%%%%%%          %%                            ",
    "%%%%                   %%          %%                            ",
    "%                      %%          %%                            ",
    "%                %%                %%                            ",
    "%                %%                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
    "%           %%   %%    %%                                       %",
    "%           %%%%%%%%%%%%%                                       %",
    "%           %%         %%                                       %",
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


