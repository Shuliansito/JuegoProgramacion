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
string* niveles[cantMapas] = { level1, level2, level3 };


int collision(int x, int y, string mapa[])
{
    if (mapa[y][x] == ' ') { return 0; }
    else if (mapa[y][x] == '%' || mapa[y][x] == '|' || mapa[y][x] == 'K') { return 1; }
    else if (mapa[y][x] == 'E') { return 2; }
    else if (mapa[y][x] == 'P') { return 3; }
    else if (mapa[y][x] == 'D') { return 4; }
    else if (mapa[y][x] == '&') { return 5; }



    return 0;
}

//Spawn Guardias

void cargarGuardias() {
    /*if (player1.nivel == 1) {
        Guardia_Ini(30, 15, 1);
        
    }*/
    if (player1.nivel == 2&&player1.guardiasMatados!=2) {
        Guardia_Ini(5, 8, 2);//Guardia 1 nivel 2
        Guardia_Ini(7, 14, 2);//Guardia 2 nivel 2
    }
}

void actionCollision() {
    int nivelActual = player1.nivel - 1;

    int col = collision(player1.X, player1.Y, niveles[nivelActual]);

    if (col == 1)
    {
        player1.X = prevX1;
        player1.Y = prevY1;
    }
    else if (col == 2)
    {

        mostrarHistoria();
        player1.nivel++;

        if (player1.nivel > 3)
            player1.nivel = 1;

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
        else if (player1.nivel == 3) {
            player1.X = 1;
            player1.Y = 12;
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
    else if (col == 3) { playing = false; }
    else if (col == 5) { canPass_1 = true; player1.canShootWeapong = true; }

    if (!puertaNivel2Abierta &&
        player1.nivel == 2 &&
        player1.guardiasMatados==2)
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
    }

    if (_kbhit())
    {
        
        gotoxy(25 + player1.X, 3 + player1.Y);
        cout << BG << " ";



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



