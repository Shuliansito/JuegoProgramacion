#include "gameLogic.h"


using namespace std;

bool playing = true;

int nivelglobal = player1.nivel;
int prevX1;
int prevY1;

int nivelActual;
bool canPass_1 = false;
bool canPass_2 = false;
bool canPass_3 = false;

char tile;
char tecla; 
char u_tecla=tecla;
//Nivel 2
int guardiasNivel2 = 2;
bool puertaNivel2Abierta = false;
string* niveles[cantMapas] = {level1, level2, level3, level4,level5,finallevel};


int collision(int x, int y, string mapa[])
{
    if (mapa[y][x] == ' ') { return 0; }
    else if (mapa[y][x] == '%' || mapa[y][x] == '|' || mapa[y][x] == 'K'||mapa[y][x]=='-'||mapa[y][x]=='N') { return 1; }
    else if (mapa[y][x] == 'E') { return 2; }
    else if (mapa[y][x] == 'P') { return 3; }
    else if (mapa[y][x] == 'D') { return 4; }
    else if (mapa[y][x] == '&') { return 5; }
    else if (mapa[y][x] == 'Y') { return 6; }
    //else if (mapa[y][x] == '*') { return 67; }



    return 0;
}

//Spawn Guardias

void cargarGuardias() {
    //X Y NIVEL
    
    if (player1.nivel == 2&&player1.guardiasMatados!=2) {
        Guardia_Ini(5, 8, 2);//Guardia 1 nivel 2
        Guardia_Ini(7, 14, 2);//Guardia 2 nivel 2
    }

    if (player1.nivel == 4&&player1.canOpenSewerage==false) {
        
        
        Guardia_Ini(33, 3, 4);//Guardia 1 nivel 4
        Guardia_Ini(35, 14, 4);//Guardia 2 nivel 4

        Guardia_Ini(58, 2, 4);//Guardia 3 nivel 4
        Guardia_Ini(59, 12, 4);//Guardia 4 nivel 4
    }
}

void actionCollision() {
    int nivelActual = player1.nivel - 1;
    std::string tipoColision[6] = {"","Pared","Sig Nivel","Guardia","Ant Nivel","Arma"};

    int col = collision(player1.X, player1.Y, niveles[nivelActual]);


    //Debug colision
    for (int i = 0; i < 6; i++){
        if(col!=0&&col==i){
            LOG_FILE("[COLISION] " + player1.getNombre() + " ha colisionado en " + "X: " + STR(player1.X) + " Y: " + STR(player1.Y) + " (Colision de tipo: "+tipoColision[i] + ")");
            LOG("[COLISION] " + player1.getNombre() + " ha colisionado en " + "X: " + STR(player1.X) + " Y: " + STR(player1.Y) + " (Colision de tipo: " + tipoColision[i] + ")");
        }
    }

    if (col == 1)
    {
        player1.X = prevX1;
        player1.Y = prevY1;
        
    }
    else if (col == 2)
    {
        
        mostrarHistoria();
        player1.nivel++;
        LOG_FILE("[NIVEL] player ha avanzado al nivel: " + STR(player1.nivel));;
        LOG("[NIVEL] "+ player1.getNombre()+" ha avanzado al nivel: " + STR(player1.nivel));
        

        player1.nivel = player1.nivel;
        // Borrar las balas al cambiar de nivel, esto hace que no se queden
        // actualizando en el siguiente mapa [BUG N002 FIXED]
        for (int i = 0; i < MAX_BULLETS; i++) {
            bullets[i].activa = false;
        }

        dibujarMapa(niveles[player1.nivel - 1], 20);

        if (player1.nivel == 1) {
            player1.X = 1;
            player1.Y = 6;
        }
        else if (player1.nivel == 2) {
            player1.X = 1;
            player1.Y = 1;
        }
        else if (player1.nivel == 3||player1.nivel==4) {
            player1.X = 1;
            player1.Y = 12;
        }
        else if (player1.nivel == 5) {
            player1.X = 30;
            player1.Y = 1;
        }
        else if (player1.nivel == 6) {
            player1.X = 1;
            player1.Y = 14;
        }
        cargarGuardias();

    }
    else if (col == 4) {
        player1.nivel--;

        if (player1.nivel > 3)
            player1.nivel = 1;
        if (player1.nivel < 0)
            player1.nivel = 1;

       
        for (int i = 0; i < MAX_BULLETS; i++) {
            bullets[i].activa = false;
        }

        dibujarMapa(niveles[player1.nivel - 1], 20);

        if (player1.nivel == 1) {
            player1.X = 63;
            player1.Y = 18;
        }
        else if (player1.nivel == 2) {
            player1.X = 63;
            player1.Y = 12;
        }
        else if (player1.nivel == 3) {
            player1.X = 45;
            player1.Y = 12;
        }


    }
    else if (col == 3) { exit(69); }
    else if (col == 5) { canPass_1 = true; player1.canShootWeapong = true; }
    else if (col == 6) { player1.canOpenSewerage=true; }
    

    if (!puertaNivel2Abierta &&player1.nivel == 2 &&player1.guardiasMatados>=2)
    {
        puertaNivel2Abierta = true;

        for (int i = 0; i < 2; i++) {
            level2[11 + i][64] = 'E';
            level2[1 + i][0] = 'D';
        }

        dibujarMapa(niveles[1], 20);
    }

    if (canPass_1) {
        for (int i = 0; i < 2; i++) {
            level1[17 + i][64] = 'E';
        }
        level1[8][52] = ' ';
        dibujarMapa(niveles[0], 20);
        canPass_1 = false;
    }

    if (player1.canOpenSewerage == true && level4[16][30] == 'K') {
        for (int i = 0; i < 2; i++) {
            level4[16][30+i] = 'E';
            level4[11+i][0] = 'D';
            
        }

        dibujarMapa(niveles[3], 20);
    }

    
    
    
    

}



void inputMovement()
{

    switch (player1.nivel)
    {
    case 1:
        tile = level1[player1.Y][player1.X];
        break;

    case 2:
        tile = level2[player1.Y][player1.X];
        break;

    case 3:
        tile = level3[player1.Y][player1.X];
        break;
    case 4:
        tile = level4[player1.Y][player1.X];
        break;
    case 5:
        tile = level5[player1.Y][player1.X];
        break;
    case 6:
        //tile = level6[player1.Y][player1.X];
        break;

    
    }

    
    if (_kbhit())
    {
        
        if (player1.nivel == 5) {
            gotoxy(25 + player1.X, 3 + player1.Y);
            cout << BG_GRIS << " ";
        }
        else if (player1.nivel == 4||player1.nivel==6) {
            gotoxy(25 + player1.X, 3 + player1.Y);
            cout << BG_LVERDE << " ";
            

        }
        else {
            gotoxy(25 + player1.X, 3 + player1.Y);
            cout << BG << " ";
        }



        char tecla = _getch();
        LOG_FILE(std::string("[INPUT] Input: ") + tecla);
        LOG(std::string("[INPUT] Input: ") + tecla);

        prevX1 = player1.X;
        prevY1 = player1.Y;

        
        //IMPORTANTE: Teclas (si... eso)
        
        if (tecla == 'd') player1.X++;
        else if (tecla == 'a') player1.X--;
        else if (tecla == 'w') player1.Y--;
        else if (tecla == 's') player1.Y++;
        else if (tecla == 'm') debugKey++;
        else if (tecla == 'h') player1.guardiasMatados++;
        
        if (shootDelay<=0) {
            if (tecla == 'j') { dispararBala(player1.X - 1, player1.Y, -1, 0);}
            else if (tecla == 'l') { dispararBala(player1.X + 1, player1.Y, 1, 0);}
            else if (tecla == 'i') { dispararBala(player1.X, player1.Y - 1, 0, -1);}
            else if (tecla == 'k') { dispararBala(player1.X, player1.Y + 1, 0, 1);}
        }
        
        actionCollision();
    }
}



