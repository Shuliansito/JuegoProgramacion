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
const string GRIS = "\033[37m";
const string NARANJA = "\033[38;2;247;156;14m";
const string ROJO = "\033[91m";
const string VERDE = "\033[92m";

void showCursor(bool show)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = show;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool keyPressed()
{
    return _kbhit();
}

int distMan(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}