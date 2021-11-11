#include "DebugCommand.h"

bool DebugCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_D) {
			bool arriba = !arriba;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void DebugCommand::execute() {
	if (arriba) {
		//donde iria el dibujar el debug?????
		//infoBar->drawDebug();
	}
}

