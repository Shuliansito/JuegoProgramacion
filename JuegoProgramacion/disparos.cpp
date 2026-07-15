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
                LOG_FILE(std::string("[DISPARO] Nueva bala en ") + std::string("X: ") + STR(bullets[i].x) + std::string(" Y: ") + STR(bullets[i].y));
                LOG(std::string("[DISPARO] Nueva bala en ") + std::string("X: ") + STR(bullets[i].x) + std::string(" Y: ") + STR(bullets[i].y));//Aviso de nueva bala en debug
                return;
            }
            
        }
        
        
    }
    
}

void actualizarBalas(std::string mapa[]) {
    if (player1.canShootWeapong) {

    
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].activa) continue;

            if (bullets[i].y < 0 || bullets[i].y >= 20 || bullets[i].x < 0 || bullets[i].x >= (int)mapa[bullets[i].y].size()) {
                bullets[i].activa = false; continue;
            }

            //Primero detecto si es pared antes de hacer el cambio de posicion [BUG N003 FIXED]
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
                for (int j = 0; j < cantGuardias; j++) {
                    if (guardia[j].x == bullets[i].x && guardia[j].y == bullets[i].y) {
                        guardia[j].vivo = false;
                       
                        break;
                    }
                }
                //cantGuardias--;
                if (cantGuardias < 0) cantGuardias = 0;
                //Logica para matar al guardia
                
                player1.guardiasMatados++;

                gotoxy(25 + nx, 3 + ny);
                std::cout << BG << " " << RESET;
                LOG_FILE("[GUARDIA] " + player1.getNombre() + " mató a un guardia en " + "X: " + STR(nx) + " Y: " + STR(ny));
                LOG("[GUARDIA] " + player1.getNombre() + " mató a un guardia en " + "X: " + STR(nx) + " Y: " + STR(ny));

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


