#include "disparos.h"

Bullet bullets[MAX_BULLETS];
bool canUseWeapon = false;

void dispararBala(int x, int y, int dx, int dy) {
    if (canUseWeapon){
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].activa) {
                bullets[i].x = x;
                bullets[i].y = y;
                bullets[i].dx = dx;
                bullets[i].dy = dy;
                bullets[i].activa = true;
                return;
            }
        }
    }
}

void actualizarBalas(std::string mapa[]) {
    if (canUseWeapon) {

    
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].activa) continue;

            if (mapa[bullets[i].y][bullets[i].x] == '%') continue;

            gotoxy(25 + bullets[i].x, 3 + bullets[i].y);
            std::cout << BG << " " << RESET;

            bullets[i].x += bullets[i].dx;
            bullets[i].y += bullets[i].dy;

            int nx = bullets[i].x;
            int ny = bullets[i].y;



            if (ny < 0 || ny >= 20 || nx < 0 || nx >= (int)mapa[ny].size()) {
                bullets[i].activa = false;
                continue;
            }

            char tile = mapa[ny][nx];

            if (tile == 'P') {
                mapa[ny][nx] = ' ';
                guardiasNivel2--;
                if (guardiasNivel2 < 0) guardiasNivel2 = 0;

                gotoxy(25 + nx, 3 + ny);
                std::cout << BG << " " << RESET;

                bullets[i].activa = false;
            }
            else if (tile == '%' || tile == '|' || tile == 'K') {
                bullets[i].activa = false;
            }
            else {
                gotoxy(25 + nx, 3 + ny);
                std::cout << NEGRO << BG << "*" << RESET;
            }
        }
    }
}


