#include "MoveCommand.h"

bool MoveCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_UP) {
			bool arriba = true;
			//llamar a lo correspondiente
		}
		else if (key == SDLK_DOWN) {
			bool arriba = false;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void MoveCommand::execute() {
	if (arriba) {
		game->setCarUp();
	}
	else game->setCarDown();
}
