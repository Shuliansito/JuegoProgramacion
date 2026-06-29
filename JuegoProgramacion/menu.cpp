#include <iostream>
#include <conio.h>
#include "mapLogic.h"
#include "Shuli.h"

extern bool inMenu;
using namespace std;
void menuLogic() {


	gotoxy(0, 0);
	std::cout << BG_NO << "En Menu"<<RESET;

	if (_kbhit) {

		char key = _getch();
		if (key == '\r') {
			inMenu = false;
		}
		else {

		}
	}
}