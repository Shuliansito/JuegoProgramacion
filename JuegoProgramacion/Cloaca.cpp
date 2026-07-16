#include "ticks.h"
#include "classes.h"
#include "Cloaca.h"

void cloacaLogic() {

	if (player1.nivel==5&&tick % 4 == 0) {
		player1.recibirDano(1);
		Beep(300, 20);
	}
}