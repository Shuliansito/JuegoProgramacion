#include <iostream>
#include <conio.h>
#include "mapLogic.h"
#include "Shuli.h"

bool inMenu = true;

using namespace std;
void menuLogic() {


	

	if (_kbhit) {

		char key = _getch();
		if (key == '\r') {
			inMenu = false;
		}
		else {

		}
	}
}