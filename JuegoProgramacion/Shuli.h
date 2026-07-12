#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <fstream> 

//Defines para el LOG 
#ifdef _DEBUG
#define LOG(msg)              OutputDebugStringA((std::string(msg) + "\n").c_str())
#define LOG_INPUT(msg)        OutputDebugStringA(("[INPUT] "    + std::string(msg) + "\n").c_str())
#define LOG_DISPARO(msg)      OutputDebugStringA(("[DISPARO] "  + std::string(msg) + "\n").c_str())
#define LOG_GUARDIA(msg)      OutputDebugStringA(("[GUARDIA] "  + std::string(msg) + "\n").c_str())
#define LOG_COLISION(msg)     OutputDebugStringA(("[COLISION] " + std::string(msg) + "\n").c_str())
#define LOG_NIVEL(msg)        OutputDebugStringA(("[NIVEL] "    + std::string(msg) + "\n").c_str())
#define STR(x)                std::to_string(x)
#endif

const std::string ESCONDER = "\033[?25l";
const std::string MOSTRAR = "\033[?25h";
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
//       COLORES       //
const std::string PARED = "\033[38;2;160;125;110m";
const std::string NEGRO = "\033[30m";
const std::string ROJO = "\033[31m";
const std::string VERDE = "\033[32m";
const std::string AMARILLO = "\033[33m";
const std::string AZUL = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BLANCO = "\033[37m";
const std::string NARANJA = "\033[38;2;255;128;0m";
const std::string ROSA = "\033[38;2;255;151;203m";
const std::string LAZUL = "\033[38;2;53;149;240m";
const std::string LVERDE = "\033[38;2;17;245;120m";
const std::string GRIS = "\033[38;2;176;174;174m";

//    COLORES FONDO  //
const std::string BG_NEGRO = "\x1B[40m";
const std::string BG_ROJO = "\x1B[41m";
const std::string BG_VERDE = "\x1B[42m";
const std::string BG_AMARILLO = "\x1B[43m";
const std::string BG_AZUL = "\x1B[44m";
const std::string BG_MAGENTA = "\x1B[45m";
const std::string BG_CYAN = "\x1B[46m";
const std::string BG_BLANCO = "\x1B[47m";
const std::string BG_NARANJA = "\x1B[48;2;255;128;0m";
const std::string BG_LAZUL = "\x1B[48;2;53;149;240m";
const std::string BG_LVERDE = "\x1B[48;2;17;245;120m";
const std::string BG = "\x1B[48;2;176;174;174m";
const std::string BG_NO = "\x1B[40m";
const std::string BG_ROSA = "\x1B[48;2;255;151;203m";


void showCursor(bool show);

void gotoxy(int x, int y);

bool keyPressed();

int distMan(int x1, int y1, int x2, int y2);


//Poner lo que este en la consola en un archivo "debug.log"
void LOG_FILE(std::string msg);