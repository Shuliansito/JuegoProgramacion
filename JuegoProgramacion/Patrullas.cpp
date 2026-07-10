#include "Patrullas.h"
#include "gameLogic.h"
#include "classes.h"
#include "mapLogic.h"


Guardia guardia[GUARDIAS_MAX];
int cantGuardias = 0;

void Guardia_Ini(int x, int y, int nivel) {
	guardia[cantGuardias].x = x;
	guardia[cantGuardias].y = y;
	guardia[cantGuardias].nivelGuardia = nivel;
    guardia[cantGuardias].vivo = true;
	cantGuardias++;
}


bool esPisable(char c) {
    return c == ' ' || c == 'X' || c == '&';
}

void Guardia_Mover(Guardia& g, std::string mapa[]) {
    mapa[g.y][g.x] = ' ';
    gotoxy(25 + g.x, 3 + g.y);
    std::cout << BG << " " << RESET;
    std::cout.flush();

    int dx[4] = { 1, -1, 0,  0 };
    int dy[4] = { 0,  0, 1, -1 };

    int opciones[4];
    int cantOpciones = 0;

    for (int d = 0; d < 4; d++) {
        int nx = g.x + dx[d];
        int ny = g.y + dy[d];
        if (ny >= 0 && ny < 20 && nx >= 0 && nx < (int)mapa[ny].size()) {
            if (esPisable(mapa[ny][nx])) {
                opciones[cantOpciones] = d;
                cantOpciones++;
            }
        }
    }

    if (cantOpciones > 0) {
        int elegido = opciones[rand() % cantOpciones];
        g.x += dx[elegido];
        g.y += dy[elegido];
    }

    if (g.x == player1.X && g.y == player1.Y) {
        playing = false;
        return;
    }

    mapa[g.y][g.x] = 'P';
    gotoxy(25 + g.x, 3 + g.y);
    std::cout << BG << AZUL << "P" << RESET;
}

void Guardia_Update(std::string nivel1[], std::string nivel2[], std::string nivel3[], int tickActual) {
    if (tickActual % 10 != 0) return;
   

    for (int i = 0; i < cantGuardias; i++) {
        if (!guardia[i].vivo) continue;
        if (guardia[i].nivelGuardia != nivelglobal) continue;
        Guardia& g = guardia[i];// Paso por referencia porque sino no se modifica la ubicacion.
        if (g.nivelGuardia == 1) Guardia_Mover(g, nivel1);
        else if (g.nivelGuardia == 2) Guardia_Mover(g, nivel2);
        else if (g.nivelGuardia == 3) Guardia_Mover(g, nivel3);
    }
}

void Guardia_Spawn() {
    Guardia_Ini(5, 8, 2);//Guardia 1 nivel 2
    Guardia_Ini(7, 14, 2);//Guardia 2 nivel 2
}
