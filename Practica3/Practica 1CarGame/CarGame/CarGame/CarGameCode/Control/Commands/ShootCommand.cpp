#include "ShootCommand.h"

bool ShootCommand::parse(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		SDL_Keycode key = event.key.keysym.sym;
		if (key == SDLK_s) {
			return true;
			//llamar a lo correspondiente
		}
	}
	return false;
}

void ShootCommand::execute() {
	if (game->getCoins() >= 1) {
		game->setCoins(-1);
		//crear bullet (no se como coño se hace)
	}
}
