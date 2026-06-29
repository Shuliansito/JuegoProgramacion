
#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"


using namespace std;

extern int nivelglobal;
extern string level0[20];
extern string level1[20];
extern string level2[20];
extern string level3[20];

void dibujarMapa(string mapa[], int filas);


int chooseMap();


