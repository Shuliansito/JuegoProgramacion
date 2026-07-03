#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"
#include "debug.h"
#include "mapLogic.h"
#include "classes.h"
#include "mecanicas.h"
using namespace std;

extern player player1;
extern bool playing;

extern int nivelglobal;
extern int prevX1;
extern int prevY1;
extern int nivelActual;
extern bool canPass_1;
extern bool canPass_2;
extern bool canPass_3;

extern char tile;

extern string* niveles[3];

int collision(int x, int y, string mapa[]);

void actionCollision();

void inputMovement();
