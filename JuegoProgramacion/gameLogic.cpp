#include "gameLogic.h"


using namespace std;

bool playing = true;

int nivelglobal = 1;
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
string* niveles[3] = { level1, level2, level3 };


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



void actionCollision() {
    int nivelActual = nivelglobal - 1;

    int col = collision(player1.X, player1.Y, niveles[nivelActual]);

    if (col == 1)
    {
        player1.X = prevX1;
        player1.Y = prevY1;
    }
    else if (col == 2)
    {
        nivelglobal++;

        if (nivelglobal > 3)
            nivelglobal = 1;

        player1.nivel = nivelglobal;

        dibujarMapa(niveles[nivelglobal - 1], 20);

        if (nivelglobal == 1) {
            player1.X = 1;
            player1.Y = 6;
        }
        else if (nivelglobal == 2) {
            player1.X = 1;
            player1.Y = 1;
        }
        else if (nivelglobal == 3) {
            player1.X = 1;
            player1.Y = 12;
        }
    }
    else if (col == 4) {
        nivelglobal--;

        if (nivelglobal > 3)
            nivelglobal = 1;
        if (nivelglobal < 0)
            nivelglobal = 1;

        player1.nivel = nivelglobal;

        dibujarMapa(niveles[nivelglobal - 1], 20);

        if (nivelglobal == 1) {
            player1.X = 63;
            player1.Y = 18;
        }
        else if (nivelglobal == 2) {
            player1.X = 63;
            player1.Y = 12;
        }
        else if (nivelglobal == 3) {
            player1.X = 45;
            player1.Y = 12;
        }


    }
    else if (col == 3) { playing = false; }
    else if (col == 5) { canPass_1 = true; canUseWeapon = true; }

    if (!puertaNivel2Abierta &&
        nivelglobal == 2 &&
        guardiasNivel2==0)
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

        prevX1 = player1.X;
        prevY1 = player1.Y;

        

        
        if (tecla == 'd') player1.X++;
        else if (tecla == 'a') player1.X--;
        else if (tecla == 'w') player1.Y--;
        else if (tecla == 's') player1.Y++;
        else if (tecla == 'm') debugKey++;
        if (shootDelay<=0) {
            if (tecla == 'j') dispararBala(player1.X - 1, player1.Y, -1, 0);
            else if (tecla == 'l') dispararBala(player1.X + 1, player1.Y, 1, 0);
            else if (tecla == 'i') dispararBala(player1.X, player1.Y - 1, 0, -1);
            else if (tecla == 'k') dispararBala(player1.X, player1.Y + 1, 0, 1);
        }
        
        actionCollision();
    }
}

