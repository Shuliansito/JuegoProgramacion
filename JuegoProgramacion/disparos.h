#pragma once

#include <string>
#include "Shuli.h"
#include "classes.h"

extern int guardiasNivel2;
extern bool canUseWeapon;
class Bullet {
public:
    int x;
    int y;
    int dx;
    int dy;
    bool activa;
};

const int MAX_BULLETS = 16;
extern Bullet bullets[MAX_BULLETS];

void dispararBala(int x, int y, int dx, int dy);
void actualizarBalas(std::string mapa[]);

