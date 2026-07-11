#include "Patrullas.h"
#include "gameLogic.h"
#include "classes.h"
#include "mapLogic.h"


Guardia guardia[GUARDIAS_MAX];
int cantGuardias = 0;

void Guardia_Ini(int x, int y, int nivel) {
    //Inicias guardias y darle una x, una y, el nivel y si esta vivo
	guardia[cantGuardias].x = x;
	guardia[cantGuardias].y = y;
	guardia[cantGuardias].nivelGuardia = nivel;
    guardia[cantGuardias].vivo = true;
	cantGuardias++;
}


bool esPisable(char c) {
    //Si es alguno de estos caracteres, devolver true
    return c == ' ' || c == 'X' || c == '&';
}

//----------------------------------------------------------//
//  Costo mucho hacer que esto funcione, odio los punteros  //
//----------------------------------------------------------//
void Guardia_Mover(Guardia& g, std::string mapa[]) {
    mapa[g.y][g.x] = ' ';
    gotoxy(25 + g.x, 3 + g.y);
    std::cout << BG << " " << RESET;
    
    //Opciones disponibles de movimiento en X y Y
    int direccionx[4] = { 1, -1, 0,  0 };
    int direcciony[4] = { 0,  0, 1, -1 };

    int opciones[4] = {};
    int cantOpciones = 0;

    //Mucho texto
    for (int d = 0; d < 4; d++) {
        int nuevax = g.x + direccionx[d];
        int nuevay = g.y + direcciony[d];
        if (nuevay >= 0 && nuevay < 20 && nuevax >= 0 && nuevax < (int)mapa[nuevay].size()) {
            if (esPisable(mapa[nuevay][nuevax])) {
                opciones[cantOpciones] = d;
                cantOpciones++;
            }
        }
    }

    // choice elige aleatoriamente entre 4 opciones y se le suma el numero del array de dx y dy
    if (cantOpciones > 0) {
        int choice = opciones[rand() % cantOpciones];
        g.x += direccionx[choice];
        g.y += direcciony[choice];
    }

    

    mapa[g.y][g.x] = 'P';
    gotoxy(25 + g.x, 3 + g.y);
    std::cout << BG << AZUL << "P" << RESET;
}
//----------------------------------------------------------------------------------//
//  No creo que sea la mejor forma de implementar los mapas en esto pero funciona   //
//----------------------------------------------------------------------------------//

void Guardia_Update(std::string nivel1[], std::string nivel2[], std::string nivel3[], int tickActual) {
    if (tickActual % 10 != 0) return;
   
    for (int i = 0; i < cantGuardias; i++) {
       
        Guardia& g = guardia[i];// Paso por referencia porque sino no se modifica la ubicacion.
        if (!g.vivo) continue;
        if (g.nivelGuardia != player1.nivel) continue;
        if (g.nivelGuardia == 1) Guardia_Mover(g, nivel1);
        else if (g.nivelGuardia == 2) Guardia_Mover(g, nivel2);
        else if (g.nivelGuardia == 3) Guardia_Mover(g, nivel3);
    }
}

