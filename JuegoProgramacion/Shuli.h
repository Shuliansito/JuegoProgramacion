#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>


using namespace std;

const string ESCONDER = "\033[?25l";
const string MOSTRAR = "\033[?25h";
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
//       COLORES       //
const string PARED = "\033[38;2;160;125;110m";
const string NEGRO =  "\033[30m";
const string ROJO  =   "\033[31m";
const string VERDE =  "\033[32m";
const string AMARILLO=  "\033[33m";
const string AZUL   = "\033[34m";
const string MAGENTA= "\033[35m";
const string CYAN   = "\033[36m";
const string BLANCO =  "\033[37m";
const string NARANJA = "\033[38;2;255;128;0m";
const string ROSA   = "\033[38;2;255;151;203m";
const string LAZUL  =  "\033[38;2;53;149;240m";
const string LVERDE = "\033[38;2;17;245;120m";
const string GRIS    = "\033[38;2;176;174;174m";

//    COLORES FONDO  //
const string BG_NEGRO   = "\x1B[40m";
const string BG_ROJO = "\x1B[41m";
const string BG_VERDE   ="\x1B[42m";
const string BG_AMARILLO = "\x1B[43m";
const string BG_AZUL    ="\x1B[44m";
const string BG_MAGENTA ="\x1B[45m";
const string BG_CYAN    ="\x1B[46m";
const string BG_BLANCO  = "\x1B[47m";
const string BG_NARANJA = "\x1B[48;2;255;128;0m";
const string BG_LAZUL   ="\x1B[48;2;53;149;240m";
const string BG_LVERDE = "\x1B[48;2;17;245;120m";
const string BG   = "\x1B[48;2;176;174;174m";
const string BG_NO = "\x1B[40m";
const string BG_ROSA   = "\x1B[48;2;255;151;203m";

void showCursor(bool show);

void gotoxy(int x, int y);

bool keyPressed();

int distMan(int x1, int y1, int x2, int y2);