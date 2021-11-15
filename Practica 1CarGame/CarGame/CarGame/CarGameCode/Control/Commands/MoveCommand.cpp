#include "MoveCommand.h"

bool MoveCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_UP) {
			arriba = true;
			return true;
			//llamar a lo correspondiente
		}
		else if (key == SDLK_DOWN) {
			arriba = false;
			return true;
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
