#include "disparos.h"

Bullet bullets[MAX_BULLETS];
bool canUseWeapon = false;
int shootDelay = 0;

void dispararBala(int x, int y, int dx, int dy) {
    
    shootDelay = 5;
    
    //Crear bala en el array
    if (player1.canShootWeapong)//Crear bala
    {
        Beep(1000, 10);
        for (int i = 0; i < MAX_BULLETS; i++) {
            if (!bullets[i].activa) {
                bullets[i].x = x;
                bullets[i].y = y;
                bullets[i].direccionx = dx;
                bullets[i].direcciony = dy;
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

            if (bullets[i].y < 0 || bullets[i].y >= 20 || bullets[i].x < 0 || bullets[i].x >= mapa[bullets[i].y].size()) {
                bullets[i].activa = false; continue;
            }

            //Primero detecto si es pared antes de hacer el cambio de posicion [BUG N003 FIXED]
            if (mapa[bullets[i].y][bullets[i].x] == '%') continue;
            
            

            if (player1.nivel != 4) {
                gotoxy(25 + bullets[i].x, 3 + bullets[i].y);
                cout << BG << " "<<RESET;

            }
            else if (player1.nivel == 4) {
                gotoxy(25 + bullets[i].x, 3 + bullets[i].y);
                cout << BG_LVERDE << " "<<RESET;

            }

            bullets[i].x += bullets[i].direccionx;
            bullets[i].y += bullets[i].direcciony;

            int nuevax = bullets[i].x;
            int nuevay = bullets[i].y;



            if (nuevay < 0 || nuevay >= 20 || nuevax < 0 || nuevax >=mapa[nuevay].size()) {
                bullets[i].activa = false;
                continue;
            }

            char tile = mapa[nuevay][nuevax];

            if (tile == 'P') {
                mapa[nuevay][nuevax] = ' ';
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
                if (player1.nivel == 4) {
                   
                    gotoxy(25 + nuevax, 3 + nuevay);
                    std::cout << BG_LVERDE << " " << RESET;
                }
                else {
                    
                    gotoxy(25 + nuevax, 3 + nuevay);
                    std::cout << BG << " " << RESET;
                }
                
                LOG_FILE("[GUARDIA] " + player1.getNombre() + " mató a un guardia en " + "X: " + STR(nuevax) + " Y: " + STR(nuevay));
                LOG("[GUARDIA] " + player1.getNombre() + " mató a un guardia en " + "X: " + STR(nuevax) + " Y: " + STR(nuevay));

                bullets[i].activa = false;
            }
            else if (tile == '%' || tile == '|' || tile == 'K' || tile == 'E' || tile == 'D') {
                bullets[i].activa = false;
            }
           
            else {
                if (player1.nivel != 4) {
                    gotoxy(25 + nuevax, 3 + nuevay);
                    cout << BG <<NEGRO<< "*"<<RESET;
                }
                else if (player1.nivel == 4) {
                    gotoxy(25 + nuevax, 3 + nuevay);
                    cout << BG_LVERDE << NEGRO << "*"<<RESET;
                }
            }
        }
    }
}


