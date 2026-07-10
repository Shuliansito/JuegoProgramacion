#include "disparos.h"

Bullet bullets[MAX_BULLETS];
bool canUseWeapon = false;
int shootDelay = 0;

void dispararBala(int x, int y, int dx, int dy) {
    
    shootDelay = 5;
    
    if (player1.canShootWeapong){
        Beep(1000, 10);
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
    if (player1.canShootWeapong) {

    
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
                cantGuardias--;
                if (cantGuardias < 0) cantGuardias = 0;
                //Logica para matar al guardia
                for (int j = 0; j < cantGuardias; j++) {
                    if (guardia[j].x == nx && guardia[j].y == ny) {
                        guardia[j].vivo = false;
                        break;
                    }
                }
                player1.guardiasMatados++;

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


