#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "classes.h"
#include "Shuli.h"

const int cantMapas = 3; //IMPORTANTE: Actualizar este valor por la cantidad de mapas
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
extern string mision[20];

void dibujarMapa(string mapa[], int filas);

void dibujarSubNivel(string submapa[], int filas);

void playerHelps();

int chooseMap();

void mostrarHistoria();

