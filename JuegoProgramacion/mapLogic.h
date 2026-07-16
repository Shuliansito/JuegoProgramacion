#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "Shuli.h"

const int cantMapas = 6; //IMPORTANTE: Actualizar este valor por la cantidad de mapas
using namespace std;
extern bool canPass_1;
extern bool canPass_2;
extern bool canPass_3;
extern int nivelglobal;
extern string controles[20]; 
extern string level0[20];
extern string level1[20];
extern string level1_1[20];
extern string level2[20];
extern string level2_2[20];
extern string level3[20];
extern string level4[20];
extern string level5[20];
extern string finallevel[20];
extern string carta[20];
extern string mision[20];

void dibujarMapa(string mapa[], int filas);

void dibujarSubNivel(string submapa[], int filas);

void playerHelps();

int chooseMap();

void mostrarHistoria();

