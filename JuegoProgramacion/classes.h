#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Shuli.h"

class player{
public:
	int X;
	int Y;
	int Vida;
	int nivel;
	std::string color;

	std::string simbolo;

	std::string nombre;

};


class enemy {
public:
	int X;
	int Y;
	int Vida;
	int damage;

};

player player1;


