
#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"


using namespace std;
extern bool canPass_1;
extern bool canPass_2;
extern bool canPass_3;
extern int nivelglobal;
extern string level0[20];
extern string level1[20];
extern string level2[20];
extern string level3[20];
extern string mision[20];

void dibujarMapa(string mapa[], int filas);

void playerHelps();

int chooseMap();


